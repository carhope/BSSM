import pandas as pd

# 1. 크롤링한 할리스 매장 데이터 불러오기
df = pd.read_csv('hollys1.csv', encoding='cp949')


# 2. 전화번호 형식 통일하기 (점(.)으로 구분된 번호를 하이픈(-)으로 통일)
def normalize_phone(phone):
    if pd.isna(phone):
        return phone
    phone = str(phone).strip()
    if phone.count('.') >= 2:      # 예: 02.6085.7858 -> 02-6085-7858
        phone = phone.replace('.', '-')
    return phone


# 3. 전화번호를 유형별로 분류하는 함수
def classify_phone(phone):
    # 전화번호가 아예 없는 경우(NaN)
    if pd.isna(phone):
        return '결측값'

    phone = str(phone).strip()

    # '.', '없음', '유선없음', 'x' 처럼 '정보 없음'을 다르게 표기한 경우들
    # → 실제 데이터를 열어보지 않으면 놓치기 쉬운 부분!
    no_info_values = ['.', '없음', '유선없음', 'x', 'X','유선전화없음']
    if phone in no_info_values:
        return '결측값'

    # 하이픈(-) 기준 첫 부분 = 지역번호 자리
    prefix = phone.split('-')[0]

    # 070(인터넷전화), 010(휴대전화), 0507(안심번호)은 지역 정보가 없으므로 별도 분류
    if prefix in ('070', '010', '0507'):
        return '인터넷전화 등'

    return '지역번호'


df['phone'] = df['phone'].apply(normalize_phone)   # 형식 통일
df['phone_type'] = df['phone'].apply(classify_phone)   # 유형 분류

print(df['phone_type'].value_counts())   # 유형별 매장 수 확인


# 4. 지역번호 - 지역명 매핑표
area_code_to_region = {
    '02': '서울', '031': '경기', '032': '인천', '033': '강원',
    '041': '충남', '042': '대전', '043': '충북', '044': '세종',
    '051': '부산', '052': '울산', '053': '대구', '054': '경북', '055': '경남',
    '061': '전남', '062': '광주', '063': '전북', '064': '제주'
}


# 5. 결측값(전화번호 없는 매장)은 제외하고 나머지만 사용
df_valid = df[df['phone_type'] != '결측값'].copy()


# 6. 지역번호 데이터만 골라서 지역명 붙이고 csv로 저장
df_area = df_valid[df_valid['phone_type'] == '지역번호'].copy()
df_area['area_code'] = df_area['phone'].str.split('-').str[0]
df_area['region'] = df_area['area_code'].map(area_code_to_region)

df_area.to_csv('hollys_지역번호별.csv', encoding='cp949', mode='w', index=False)
print('hollys_지역번호별.csv 저장 완료 (%d개 매장)' % len(df_area))


# 7. 070/010/0507 등 지역 정보 없는 번호만 골라서 csv로 저장
df_internet = df_valid[df_valid['phone_type'] == '인터넷전화 등'].copy()
df_internet.to_csv('hollys_인터넷전화등.csv', encoding='cp949', mode='w', index=False)
print('hollys_인터넷전화등.csv 저장 완료 (%d개 매장)' % len(df_internet))


# 8. 제외된 결측값 매장 수 확인하기
df_missing = df[df['phone_type'] == '결측값']
print('전화번호 정보가 없어서 제외된 매장 수: %d개' % len(df_missing))