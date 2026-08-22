'''/*기준 점수 int p
p입력 받기
n개의 이름과 점수 입력받기 한줄에 이름과 점수 한개씩 n개임

기준을 넘는 사람의 수 int passpeople = 0
이름을 저장하는 배열 char name[n][100];
점수를 저장하는 배열 int score[n]
통과한 사람 인덱스 저장 배열 int pass[100];
n번 for 문으로 이름, 점수을 입력받고
점수가 p 이상이면 
pass[passpeople] = *name[i]
passpeople ++;
출력 
printf("%d\n",passpeople);
for문을 써서 
pass[i]에 있는 이름 출력
score[i]에 있는 점수 출력
*/
'''
n,p = map(int,input().split(' '))
passpeople = 0
pas = []
score = []
name = []

for i in range(n):
	scorename = input()
	score.append(int(scorename[scorename.find(' '):]))
	name.append(scorename[:scorename.find(' ')])
	if score[i]>=p:
		passpeople +=1
		pas.append(name[i])

print(passpeople)
for i in pas:
	print(i,end=" ")
