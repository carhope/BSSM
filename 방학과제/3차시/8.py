def push(stack,data):
	stack.append(data)

def size(stack):
	return len(stack)

def front(stack):
	return stack[0]
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
			print(stack.pop(0))
		else:
			print(-1)
	elif op[0:5] == "FRONT":
		if stack:
			print(front(stack))
		else:
			print(-1)