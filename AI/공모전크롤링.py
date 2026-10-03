import requests
from bs4 import BeautifulSoup
import pandas as pd
import time
import re

BASE_URL = "https://www.allforyoung.com"
LIST_URL = BASE_URL + "/posts/contest"

headers = {
    "User-Agent": "Mozilla/5.0"
}

results = []


# ==================================================
# 1. 고등학생 참가 가능 여부
# ==================================================
def can_highschool_apply(text):
    clean = re.sub(r"\s+", "", text)

    # 고등학생이 명확하게 포함되는 표현
    allow_keywords = [
        "고등학생",
        "고교생",
        "중고등학생",
        "중·고등학생",
        "청소년",
        "전국누구나",
        "누구나",
        "제한없음",
        "전국민",
        "대한민국국민"
    ]

    for keyword in allow_keywords:
        if keyword.replace(" ", "") in clean:
            return True

    return False


# ==================================================
# 2. 참가자격 깔끔하게 추출
# ==================================================
def extract_qualification(text):

    # 참가자격을 나타낼 수 있는 표현
    start_pattern = (
        r"(?:접수\s*자격|참가\s*자격|응모\s*자격|"
        r"지원\s*자격|참가\s*대상|공모\s*대상|"
        r"지원\s*대상|모집\s*대상)"
        r"\s*[:：]?\s*"
    )

    # 다음 항목이 등장하면 종료
    end_pattern = (
        r"(?="
        r"접수\s*기간|공모\s*기간|모집\s*기간|"
        r"출품\s*한도|출품\s*규격|공모\s*주제|"
        r"공모\s*내용|접수\s*방법|응모\s*방법|"
        r"참가\s*방법|지원\s*방법|시상\s*내역|"
        r"시상\s*규모|문의\s*사항|문의처|"
        r"주최|주관|$"
        r")"
    )

    match = re.search(
        start_pattern + r"(.{1,300}?)" + end_pattern,
        text,
        re.DOTALL | re.IGNORECASE
    )

    if match:
        qualification = match.group(1)
        qualification = re.sub(r"\s+", " ", qualification)
        return qualification.strip(" :-")

    return ""


# ==================================================
# 3. 시상내역 깔끔하게 추출
# ==================================================
def extract_prize(text):

    start_pattern = (
        r"(?:시상\s*내역|시상\s*규모|수상\s*혜택|"
        r"상금\s*내역|총\s*상금)"
        r"\s*[:：]?\s*"
    )

    end_pattern = (
        r"(?="
        r"문의\s*사항|문의처|유의\s*사항|"
        r"접수\s*방법|응모\s*방법|참가\s*방법|"
        r"홈페이지|첨부\s*파일|$"
        r")"
    )

    match = re.search(
        start_pattern + r"(.{1,700}?)" + end_pattern,
        text,
        re.DOTALL | re.IGNORECASE
    )

    if match:
        prize = match.group(1)
        prize = re.sub(r"\s+", " ", prize)

        return prize.strip(" :-")

    return ""


# ==================================================
# 4. 목록 5페이지 순회
# ==================================================
post_ids = []

for page in range(1, 6):

    url = f"{LIST_URL}?page={page}"

    print(f"\n목록 {page}페이지 수집 중...")

    try:
        response = requests.get(
            url,
            headers=headers,
            timeout=10
        )

        response.raise_for_status()

        soup = BeautifulSoup(
            response.text,
            "html.parser"
        )

        # Next.js 내부 데이터에서 공모전 ID 추출
        for script in soup.find_all("script"):

            text = script.string

            if not text:
                continue

            ids = re.findall(
                r'\\"type\\":\\"(?:post|ad)\\",'
                r'\\"data\\":\{\\"id\\":(\d+)',
                text
            )

            for post_id in ids:

                if post_id not in post_ids:
                    post_ids.append(post_id)

        print("현재까지 찾은 공모전:", len(post_ids))

    except Exception as e:
        print("목록 페이지 오류:", e)

    # 서버 부담 방지
    time.sleep(1)


# 혹시 100개보다 많이 발견되면 100개까지만
post_ids = post_ids[:100]

print()
print("============================")
print("검사할 공모전:", len(post_ids))
print("============================")


# ==================================================
# 5. 상세페이지 크롤링
# ==================================================
for index, post_id in enumerate(post_ids):

    url = f"{BASE_URL}/posts/{post_id}"

    print(
        f"[{index + 1}/{len(post_ids)}] "
        f"{url}"
    )

    try:

        response = requests.get(
            url,
            headers=headers,
            timeout=10
        )

        response.raise_for_status()

        soup = BeautifulSoup(
            response.text,
            "html.parser"
        )

        # HTML 전체 텍스트
        text = soup.get_text(
            " ",
            strip=True
        )

        # --------------------------
        # 공모전 제목
        # --------------------------
        title = ""

        title_tag = soup.find("title")

        if title_tag:
            title = title_tag.get_text(strip=True)

            # "| 요즘것들" 제거
            title = re.sub(
                r"\s*\|\s*요즘것들\s*$",
                "",
                title
            )


        # --------------------------
        # 참가자격
        # --------------------------
        qualification = extract_qualification(text)

        if not qualification:
            print("  → 참가자격 찾지 못함")
            time.sleep(1)
            continue


        # --------------------------
        # 고등학생 여부
        # --------------------------
        if not can_highschool_apply(qualification):

            print(
                "  → 제외:",
                qualification[:60]
            )

            time.sleep(1)
            continue


        # --------------------------
        # 시상내역
        # --------------------------
        prize = extract_prize(text)


        # --------------------------
        # CSV 데이터 추가
        # --------------------------
        results.append({
            "공모전명": title,
            "참가자격": qualification,
            "고등학생 참가가능": "O",
            "시상내역": prize,
            "상세페이지": url
        })

        print("  → ★ 고등학생 참가 가능")

    except Exception as e:

        print(
            "  → 상세페이지 오류:",
            e
        )


    # 요청 간격
    time.sleep(1)


# ==================================================
# 6. CSV 저장
# ==================================================
df = pd.DataFrame(
    results,
    columns=[
        "공모전명",
        "참가자격",
        "고등학생 참가가능",
        "시상내역",
        "상세페이지"
    ]
)

df.to_csv(
    "highschool_contests.csv",
    index=False,
    encoding="utf-8-sig"
)


# ==================================================
# 7. 결과 출력
# ==================================================
print()
print("===================================")
print("크롤링 완료")
print("검사한 공모전 :", len(post_ids))
print("고등학생 참가 가능 :", len(df))
print("저장 파일 : highschool_contests.csv")
print("===================================")

if len(df) > 0:

    print()
    print("수집 결과 미리보기")

    print(
        df[
            [
                "공모전명",
                "참가자격"
            ]
        ].head(10)
    )