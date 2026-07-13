def asemble(a,b):   
    bb = b[1]*-1
    Q = []
    xxx = xx = x=a[0]
    Q.append(a[0])
    xx = xxx*bb+a[1]
    x = xxx*bb+a[2]
    Q.append(xx)


    return '몫 : '+str(Q),'나머지 : ' + str(x)
user = list(map(int, input('3개의 숫자 배열 띄어서 입력').split()))
user2 = list(map(int, input('2개의 숫자 배열 띄어서 입력').split()))
print(asemble(user, user2))
