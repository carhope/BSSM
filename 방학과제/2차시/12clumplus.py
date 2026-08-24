r,c = map(int,input().split())

score = [0]*c

for i in range(r):
	
	cc = list(map(int, input().split()))
	for k in range(c):
		score[k] += cc[k]
for j in score:
	print(j,end=' ')