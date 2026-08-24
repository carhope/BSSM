galho = input()
stack = []
tlq = 0
for i in galho:

	if i=="(":
		tlq +=1
	elif i==")":
		tlq -=1
	if tlq <0:
		print("NO")
		tlq = -6974
		break
if tlq == 0:
	print("YES")
