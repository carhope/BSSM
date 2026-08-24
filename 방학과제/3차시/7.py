def push(stack,data):
	stack.append(data)

def size(stack):
	return len(stack)

n = int(input())

stack = []
for i in range(n):
	op = input()

	if op[0:4] == "PUSH":
		op, data = map(str, op.split())
		data = int(data)
		push(stack,data)
	elif op[0:4] == "SIZE":
		print(size(stack))
	elif op[0:3]=="POP":
		if stack:
			print(stack.pop())
		else:
			print(-1)
