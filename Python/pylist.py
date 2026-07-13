'''append() 맨뒤에 값 추가
insert() 
extend()
index()
pop() 맨 뒤 값 꺼내서 return ,삭제
remove() 그냥 삭제
clear() 모두 삭제
count() 세기
sort() 작은 순서대로 정렬'''

list1 = []
text = "cha hiu mang"

for i in text:
    list1.append(i)
for k in range(len(list1)):
    print(list1.pop(),end ="")