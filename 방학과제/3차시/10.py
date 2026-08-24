n = int(input())

pay = list(map(int,input().split()))
stack = []

for i in pay:
	if i == 0:
		stack.pop()
	else:
		stack.append(i)
print(sum(stack))
