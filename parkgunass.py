alp = 'abcdefghijklnmopqrstuvxyz'

a,b,c = map(str, input().split(''))
p=[a,b,c]
o = len(alp)
for i in p:
    if alp.find(c) > o:
        print(alp[o-alp.find(c)+3])
    else:
        print(alp[alp.find(c)+3])