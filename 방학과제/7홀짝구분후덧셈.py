n = int(input())

holplus = 0
jaackplus = 0
cur = list(map(int, input().split(' ')))

for l in cur:
	if l % 2==0:
		jaackplus += l
	else:
		holplus += l

print(jaackplus, holplus)
		