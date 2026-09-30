def hanoi(n,a,b,c):
    if n==0:
        return
    hanoi(n-1,a,c,b)
    print(a,"->",c)
    hanoi(n-1,b,a,c)

n = int(input())
print(hanoi(n,'a','b','c'))