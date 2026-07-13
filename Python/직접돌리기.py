print( 'cat' < 'dog')

print( 'cat' < 'Cat')
yourimfor = "1216차희망성적 : 100"
print(yourimfor[:])
print("학번 :", yourimfor[0:5])
print("이름 :", yourimfor[4:7])
print(yourimfor[7:])
print(yourimfor[::-1]) # 거꾸로 출력!
print(yourimfor[::-2])

name = "cha despair"
print(name[-1:-8:-1])

s = "안녕"
old_id = id(s)
print("처음 주소 :",old_id)
s = s+"세상아"
new_id = id(s)
print("추가한 문자열 주소 :",new_id)
print("처음과 지금의 동일여부 :", old_id == new_id)
comeIn = input("누가 들어왔나요?") # -> 정건우 입력 -> 변수 자동으로 문자열

print(f"하이 {comeIn}") #-> 하이 정건우 출력
print(f"{comeIn[1:3]}야 잘했어") #건우야 잘했어 출력
print(f"{input()}님 환영합니다") #-> 함수도 f-string으로 활용 가능
# *중요* f-string에서 입력 받은 내용 저장
print(f"{(name := input())}님 하이요 {name}")
print(name)
date = input()
year = date[:4]
month = date[4:6]
day = date[6:8]
print(year,month,day,sep="-")