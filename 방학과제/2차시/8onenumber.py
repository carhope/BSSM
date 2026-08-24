n = int(input())

num = list(map(int,input().split(' ')))
unique = []
for i in num:
	if i not in unique:
		unique.append(i)

unique.sort()

for i in unique:
	print(i,end=' ')