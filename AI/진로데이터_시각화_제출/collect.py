"""교육부·커리어넷 공식 집계표 → 2022~2025년 고등학생 원본 CSV.

python collect.py (필요 패키지: pdfplumber)
원문 표의 값을 보존한다. 개인정보가 있는 학생별 원자료가 아닌 공개 집계자료다.
"""
import csv
import hashlib
import json
import re
import urllib.request
import xml.etree.ElementTree as ET
import zipfile
from pathlib import Path

import pdfplumber

ROOT = Path(__file__).resolve().parent
ORIGINALS = ROOT / "originals"
COLLECTED = "2026-10-08"
SOURCES = {
    2022: {"file": "career_survey_2022_press.hwpx", "page": "https://www.moe.go.kr/boardCnts/viewRenew.do?boardID=294&boardSeq=93422&lev=0", "url": "https://www.moe.go.kr/boardCnts/fileDown.do?m=020402&s=moe&fileSeq=a9d8d22bf4f8c7549b5154f0f56f8056"},
    2023: {"file": "career_survey_2023_press.hwpx", "page": "https://www.moe.go.kr/boardCnts/viewRenew.do?boardID=294&boardSeq=97201&lev=0", "url": "https://www.moe.go.kr/boardCnts/fileDown.do?m=0204&s=moe&fileSeq=0f67b3077175d3d15da7e25504d1aca2"},
    2024: {"file": "career_survey_2024_press.hwpx", "page": "https://www.moe.go.kr/boardCnts/viewRenew.do?boardID=294&boardSeq=101832&lev=0", "url": "https://www.moe.go.kr/boardCnts/fileDown.do?m=020402&s=moe&fileSeq=c496bb6bae5f38ac63b3ecde886a1bc8"},
    2025: {"file": "career_survey_2025.pdf", "page": "https://www.career.go.kr/cloud/w/courseEdu/course2025", "url": "https://www.career.go.kr/data/data_2009/course/use/2025%EB%85%84%20%EC%B4%88%EC%A4%91%EB%93%B1%20%EC%A7%84%EB%A1%9C%EA%B5%90%EC%9C%A1%20%ED%98%84%ED%99%A9%EC%A1%B0%EC%82%AC.pdf"},
}


def save_csv(name, rows):
    with (ROOT / name).open("w", newline="", encoding="utf-8-sig") as f:
        writer = csv.DictWriter(f, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    print(f"{name}: {len(rows)}행")


def hwpx_tables(path):
    ns = {"hp": "http://www.hancom.co.kr/hwpml/2011/paragraph"}
    tables = []
    with zipfile.ZipFile(path) as archive:
        for name in sorted(archive.namelist()):
            if not (name.startswith("Contents/section") and name.endswith(".xml")):
                continue
            root = ET.fromstring(archive.read(name))
            for i, table in enumerate(root.findall(".//hp:tbl", ns), start=1):
                rows = [[" ".join(e.text or "" for e in cell.iter() if e.tag.endswith("}t"))
                         for cell in row.findall("./hp:tc", ns)]
                        for row in table.findall("./hp:tr", ns)]
                tables.append((f"{name} hp:tbl[{i}]", rows))
    return tables


def provenance(source_year, location, table, job=False):
    source = SOURCES[source_year]
    return {
        "분모_설명": "희망 직업이 있다고 응답한 고등학생" if job else "조사에 응답한 고등학생 전체",
        "가중치_적용": "미적용" if job else "적용",
        "원본파일": source["file"], "원문위치": location, "원문표": table,
        "출처_URL": source["page"], "수집일": COLLECTED,
    }


def main():
    ORIGINALS.mkdir(exist_ok=True)
    for source in SOURCES.values():
        path = ORIGINALS / source["file"]
        if not path.exists():
            req = urllib.request.Request(source["url"], headers={"User-Agent": "Mozilla/5.0"})
            with urllib.request.urlopen(req, timeout=60) as response:
                path.write_bytes(response.read())
        source["sha256"] = hashlib.sha256(path.read_bytes()).hexdigest()
    tables = {year: hwpx_tables(ORIGINALS / SOURCES[year]["file"]) for year in [2022, 2023, 2024]}
    jobs = []
    for year in [2022, 2023, 2024]:
        candidates = [(loc, t) for loc, t in tables[year]
                      if any(len(r) == 7 and r[0].strip() == "20" for r in t)
                      and "CEO" in " ".join(" ".join(r) for r in t)]
        assert len(candidates) == 1, (year, len(candidates))
        location, table = candidates[0]
        for row in table:
            if len(row) == 7 and row[0].strip().isdigit():
                jobs.append({"조사연도": year, "학교급": "고등학생", "순위": row[0], "직업명": row[5],
                             "비율_퍼센트": row[6], **provenance(year, location, "학생의 희망 직업 - 상위 20개", True)})
    with pdfplumber.open(ORIGINALS / SOURCES[2025]["file"]) as pdf:
        text_jobs = pdf.pages[144].extract_text()
        text_plan = pdf.pages[160].extract_text()
        text_interest = pdf.pages[167].extract_text()
    pattern = r"^(\d+)\s+(.+?)\s+(\d+\.\d+)\s+(.+?)\s+(\d+\.\d+)\s+(.+?)\s+(\d+\.\d+)$"
    for line in text_jobs.splitlines():
        match = re.match(pattern, line)
        if match:
            rank, _, _, _, _, job, percentage = match.groups()
            jobs.append({"조사연도": 2025, "학교급": "고등학생", "순위": rank, "직업명": job,
                         "비율_퍼센트": percentage, **provenance(2025, "PDF 145쪽 / 본문 93쪽", "표 3-2-16", True)})
    assert len(jobs) == 80
    save_csv("hope_jobs_2022_2025_raw.csv", jobs)

    # 이전 연도 수치는 2024년 공식 보도자료의 동일 지표 시계열 표에서 수집한다.
    plans, interest = [], []
    for location, table in tables[2024]:
        if table[0][0].strip() == "학교급" and "2015년" in table[0] and len(table[1]) == 11:
            for year, value in zip(table[0][1:], table[1][1:]):
                year = int(year.strip().replace("년", ""))
                if year >= 2022:
                    plans.append({"조사연도": year, "학교급": "고등학생", "진로계획": "창업", "비율_퍼센트": value,
                                  **provenance(2024, location, "고등학생 졸업 후 진로계획(창업)")})
        flat = " ".join(" ".join(row) for row in table)
        if "2020년" in flat and "관심이 없음" in flat:
            for row in table[1:]:
                if len(row) == 6 and re.match(r"^202[2-4]년", row[0]):
                    year = int(row[0].strip().replace("년", ""))
                    for category, value in zip(table[0][1:], row[1:]):
                        interest.append({"조사연도": year, "학교급": "고등학생", "관심정도": category,
                                         "비율_퍼센트": value, **provenance(2024, location, "창업에 대한 관심 정도")})
    match = re.search(r"^창업\s+(\d+\.\d+)\s*$", text_plan, re.M)
    assert match
    plans.append({"조사연도": 2025, "학교급": "고등학생", "진로계획": "창업", "비율_퍼센트": match.group(1),
                  **provenance(2025, "PDF 161쪽 / 본문 109쪽", "표 3-2-31")})
    categories = ["전혀 관심이 없음", "관심이 없음", "보통", "관심이 있음", "매우 관심이 있음"]
    for line in text_interest.splitlines():
        match = re.match(r"^(.+?)\s+((?:\d+\.\d+\s+){5}\d+\.\d+)\s*$", line)
        if match and match.group(1) in categories:
            interest.append({"조사연도": 2025, "학교급": "고등학생", "관심정도": match.group(1),
                             "비율_퍼센트": match.group(2).split()[-1],
                             **provenance(2025, "PDF 168쪽 / 본문 116쪽", "표 3-2-38 전체 열")})
    assert len(plans) == 4 and len(interest) == 20
    # 2022·2023 관심 분포는 해당 연도 원문에서도 교차 확인한다.
    for year in [2022, 2023]:
        found = False
        for _, table in tables[year]:
            if "관심이 없음" not in " ".join(" ".join(row) for row in table):
                continue
            for row in table:
                if row[0].strip() == str(year) and len(row) >= 6:
                    expected = [r["비율_퍼센트"] for r in interest if r["조사연도"] == year]
                    assert row[1:6] == expected
                    found = True
        assert found, year
    save_csv("startup_plan_2022_2025_raw.csv", plans)
    save_csv("startup_interest_2022_2025_raw.csv", interest)
    (ROOT / "sources_manifest.json").write_text(json.dumps(SOURCES, ensure_ascii=False, indent=2), encoding="utf-8")


if __name__ == "__main__":
    main()
