n = int(input())
fourspace = [0,0,0,0,0]
for i in range(n):
	x,y = int(input().split(' '))
	if x >0:
		if y>0:
			fourspace[1] +=1
		elif y<0:
			fourspace[4]+=1
		else:
			fourspace[0]+=1
	elif x<0:
		if y>0:
			fourspace[2]+=1
		elif y<0:
			fourspace[3]+=1
		else:
			fourspace[0]+=1
	else:
		fourspace[0]+=1

for i in range(0,5):
	print(fourspace[i],end=" ")