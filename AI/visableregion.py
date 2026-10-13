import pandas as pd
import matplotlib.pyplot as plt

# 한글이 깨지지 않도록 폰트 설정 (운영체제에 따라 폰트 이름이 다를 수 있음)
plt.rcParams['font.family'] = 'Malgun Gothic'   # Mac에서는 'AppleGothic'으로 변경
plt.rcParams['axes.unicode_minus'] = False       # 마이너스(-) 기호 깨짐 방지

# 전처리에서 만든 지역별 매장 수 데이터 불러오기
df = pd.read_csv('hollys_지역별_매장수.csv', encoding='cp949')

# 선 그래프 그리기
plt.plot(df['region'], df['매장수'], color='orange', marker='o', label='매장 수')

plt.title('지역별 할리스 매장 수')
plt.xlabel('지역')
plt.ylabel('매장 수(개)')
plt.legend()

plt.show()