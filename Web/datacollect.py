import requests
from  bs4 import BeautifulSoup

# 1. 주소 설정
url = "https://openapi.gg.go.kr/Grdupthhigh?KEY=35dc4317966448409c004a4914154b9d"

# 2. 데이터 가져오기
response = requests.get(url)

# 3. XML 분석기 돌리기
soup = BeautifulSoup(response.text, "xml")

# 4. 각 학교 정보(row)를 하나씩 확인
rows = soup.find_all("row")

print(f"{'학교명':<20} | {'취업률(%)':<10}")
print("-" * 40)

for row in rows:
    # 태그 이름으로 데이터 찾기
    name = row.find("SCHOOL_NM").text    # 학교 이름
    job_rt = row.find("EMPLYMT_RT").text  # 취업률
    
    # 화면에 예쁘게 출력
    print(f"{name:<20} | {job_rt:<10}")