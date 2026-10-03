import pandas as pd

# CSV 파일 불러오기
df = pd.read_csv("AI/hollys1_utf8.csv")

# 2층으로 인정할 표현
floor2_patterns = [
    "1층~2층",
    "1층, 2층",
    "1F~2F",
    "1~2층",
    "1,2층",
    "1~3층",
    "1~4층",
    "2~3층",
    "2~4층",
    "B1~2층",
    "2층",
    "2F"
]


def find_floor2(address):
    address = str(address)

    # 지하 2층은 지상 2층이 아니므로 제외
    if "지하2층" in address or "지하 2층" in address or "B2" in address:
        return None

    # 2층을 포함하는 표현 찾기
    for pattern in floor2_patterns:
        if pattern in address:
            return pattern

    return None


# 2층으로 판단한 근거 저장
df["2층으로 판단한 근거"] = df["address"].apply(find_floor2)

# 2층으로 판단된 매장만 남기기
floor2_df = df[df["2층으로 판단한 근거"].notna()]

# 결과 저장
floor2_df.to_csv(
    "hollys_2floor.csv",
    index=False,
    encoding="utf-8-sig"
)

# 결과 확인
print("전체 매장 수:", len(df))
print("2층 매장 수:", len(floor2_df))
print()
print(floor2_df[["store", "address", "2층으로 판단한 근거"]].to_string(index=False))
print()
print("hollys_2floor.csv 저장 완료!")