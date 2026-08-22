n = int(input())
common = 0
commonname = []

one = list(map(str, input().split(' ')))
m = int(input())

two = list(map(str,input().split(' ')))

for i in one:
	for j in two:
		if i == j:
			common += 1
			commonname.append(i)

if common>0:
	print(common)
	for i in commonname:
		print(i,end=' ')
else:
	print('NONE')