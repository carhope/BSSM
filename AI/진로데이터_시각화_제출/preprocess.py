"""원본 CSV를 정리하고 연도별 비교표·2025년 대비 변화량을 만든다.
실행: python preprocess.py (외부 패키지 필요 없음)
"""
import csv
from decimal import Decimal
from pathlib import Path

ROOT = Path(__file__).resolve().parent


def read_csv(name):
    with (ROOT / name).open(encoding="utf-8-sig", newline="") as f:
        rows = list(csv.DictReader(f))
    for row in rows:
        for key, value in row.items():
            row[key] = " ".join(value.split())
        row["조사연도"] = int(row["조사연도"])
        row["비율_퍼센트"] = Decimal(row["비율_퍼센트"])
        assert 0 <= row["비율_퍼센트"] <= 100
        if "순위" in row:
            row["순위"] = int(row["순위"])
    return rows


def save_csv(name, rows):
    with (ROOT / name).open("w", encoding="utf-8-sig", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=list(rows[0]))
        writer.writeheader()
        writer.writerows(rows)
    print(f"{name}: {len(rows)}행")


def main():
    jobs = read_csv("hope_jobs_2022_2025_raw.csv")
    plans = read_csv("startup_plan_2022_2025_raw.csv")
    interests = read_csv("startup_interest_2022_2025_raw.csv")
    # 직업 이름의 표기만 통일하고, 수치와 순위는 변경하지 않는다.
    for row in jobs:
        if row["직업명"] in {"경영자/CEO", "최고경영자(CEO)/경영자"}:
            row["직업명"] = "CEO/경영자"
    for data, category in [(jobs, "직업명"), (plans, "진로계획"), (interests, "관심정도")]:
        keys = [(r["조사연도"], r[category]) for r in data]
        assert len(keys) == len(set(keys)), "중복 행 확인 필요"
    summary = []
    for year in range(2022, 2026):
        year_jobs = [r for r in jobs if r["조사연도"] == year]
        year_plan = [r for r in plans if r["조사연도"] == year]
        year_interest = [r for r in interests if r["조사연도"] == year]
        assert len(year_jobs) == 20 and len(year_plan) == 1 and len(year_interest) == 5
        ceo = [r for r in year_jobs if r["직업명"] == "CEO/경영자"]
        assert len(ceo) == 1
        assert abs(sum(r["비율_퍼센트"] for r in year_interest) - 100) <= Decimal("0.2")
        # 반올림된 원문 값을 합산한다. 합계가 100.1이어도 임의 보정하지 않는다.
        positive = sum(r["비율_퍼센트"] for r in year_interest
                       if r["관심정도"] in {"관심이 있음", "매우 관심이 있음"})
        summary.append({"조사연도": year, "CEO_경영자_희망_퍼센트": ceo[0]["비율_퍼센트"],
                        "CEO_경영자_순위": ceo[0]["순위"],
                        "졸업직후_창업계획_퍼센트": year_plan[0]["비율_퍼센트"],
                        "창업_긍정관심_퍼센트": positive})
    save_csv("career_2022_2025_clean.csv", summary)
    changes = []
    for old in summary[:-1]:
        new = summary[-1]
        changes.append({"기준연도": old["조사연도"], "비교연도": 2025,
                        **{key.replace("퍼센트", "변화_pp"): new[key] - old[key]
                           for key in new if key.endswith("퍼센트")}})
    save_csv("change_to_2025.csv", changes)
    for row in summary:
        print(row)


if __name__ == "__main__":
    main()
