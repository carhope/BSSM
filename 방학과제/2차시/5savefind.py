n = int(input())
name = []
price = []
for i in range(n):
	nameprice = input()
	name.append(nameprice[:nameprice.find(' ')])
	price.append(nameprice[nameprice.find(' ')+1:])

q = int(input())
for i in range(q):
	object = input()
	if object in name:
		print(price[name.index(object)])
	else :
		print('-1')