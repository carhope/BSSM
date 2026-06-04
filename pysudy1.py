print(10//3)
print(10/3)
print(0.1+0.2)
print(10 | 1)
a = 223
b = 267
print(a, b) #여러개 출력
print("줄바꿈 자동임")
print("근데 이렇게 한다면", end="")
print("짜잔"*10)
print("근데요","나는","왜","나일까요?", sep="-")
g = 100
an = 100
if g>an :
	print("정건우 win")
elif g==an :
	print("와 이거 실화냐 가슴이 웅장해 지는 싸움이다.")
else :
	print("안도현 win")
a = int(input())
result = "홀수" if a%2==1 else "짝수"
print(result)

score = int(input())
grade = "A" if score>=90 else("B" if score >=80 else "C")
print(grade)