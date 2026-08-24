n,m = map(int,input().split())

reserve = ["O"]*(n+1)

re = list(map(int,input().split()))

for i in range(m):
	reserve[re[i]] = "X"

for i in range(1,n+1):
	print(reserve[i],end='')
