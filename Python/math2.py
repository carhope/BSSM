def asemble(a,b):   
    bb = b[1]*-1
    Q = []
    R = []
    for i in a:
        if i == a[0]:
            Q.append(i)
            c = i

        elif i == a[-1]:
            R.append(c*bb+i)


        else:
            Q.append(c*bb+i)
            c = c*bb+i
            
            

    return '몫 : '+str(Q),'나머지 : ' + str(R)
user = list(map(int, input('3개의 숫자 배열 띄어서 입력').split()))
user2 = list(map(int, input('2개의 숫자 배열 띄어서 입력').split()))
print(asemble(user, user2))