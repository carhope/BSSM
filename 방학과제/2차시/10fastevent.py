n = int(input())
event = []

for i in range(n):
	name,mon,day = input().split()
	event.append((int(mon),int(day),name))

event.sort()

for i in range(n):
	print(event[i][2],end=' ')
	