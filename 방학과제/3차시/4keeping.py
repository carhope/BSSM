n = int(input())

li = list(map(int, input().split()))
long=1
longest = 1
for i in range(n-1):
	if li[i+1]>li[i]:
		long +=1
	else:
		if long>longest:
			longest = long
		long=1

if long > longest:
	longest = long
print(longest)