
user_input = input()
moum = 0
moummnum = ['a','A','e','E','i','I','o','O','u','U']
for i in user_input:
	if i in moummnum:
		moum+=1

print(moum)