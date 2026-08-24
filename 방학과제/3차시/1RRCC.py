r,c = map(int, input().split())
cr = [[] for _ in range(c)]
for i in range(r):
	cc = list(map(int, input().split()))
	for k in range(c):
		cr[k].append(cc[k])
for k in cr:
	for j in k:
		print(j,end=' ')
	print()