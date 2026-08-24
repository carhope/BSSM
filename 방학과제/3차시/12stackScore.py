n = int(input())

score = list(map(int,input().split()))
nuger = 0
for i in score:
	nuger += i
	print(nuger,end=' ')