alp = 'abcdefghijklnmopqrstuvwxyz'#
print(len(alp))
a,b,c = map(str, input().split(' '))
p=[a,b,c]
o = len(alp)
for i in p:
    if alp.find(i) > o:
        print(alp[o-alp.find(i)+3])
    else:
        print(alp[alp.find(i)+3])