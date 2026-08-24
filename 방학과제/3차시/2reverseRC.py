h,w = map(int,input().split())

r,c = map(int, input().split())

control = input()

for i in control:
	if i == "U":
		if r<h:
			r +=1
	elif i =="D":
		if r>h:
			r-=1
	elif i =="R":
		if c<w:
			c+=1
	elif i== "L":
		if c>w:
			c-=1

print(r,c)