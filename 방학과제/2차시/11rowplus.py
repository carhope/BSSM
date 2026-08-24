r,c = map(int,input().split())
score = []
for i in range(r):
	cc = sum(map(int,input().split()))
	score.append(cc)

for k in score:
	print(k,end=' ')