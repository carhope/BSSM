n = int(input())
count = {}
for i in range(n):
	ex = input()
	expander = ex[ex.find('.')+1:]
	if expander in count:
		count[expander] += 1
	else:
		count[expander] = 1

for key,value in sorted(count.items()):
	print(key,value)