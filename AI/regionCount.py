import pandas as pd

# 6주차에서 만든 지역번호별 매장 데이터 불러오기
df = pd.read_csv('hollys_지역번호별.csv', encoding='cp949')

# region 컬럼의 값(지역명)별로 몇 번 나오는지 세기
region_counts = df['region'].value_counts().reset_index()
region_counts.columns = ['region', '매장수']

# 시각화에 사용할 수 있도록 새로운 csv 파일로 저장
region_counts.to_csv('hollys_지역별_매장수.csv', encoding='cp949', index=False)

print(region_counts)