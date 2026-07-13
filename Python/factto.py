def fact(n):
    result = 1
    for i in range(1,n+1):
        result = result*i
    return 0
def ff(n):
    if n==1:
        return 1
    return n * ff(n-1)
def f(k):
    if k==0:
        return
    
    f(k-1)
     