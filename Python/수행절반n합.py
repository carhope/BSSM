def sum_half(n):
    if n==1:
        return 1
    m = (n-1)//2
    return 2 * sum_half(n//2) + m*m
n = int(input())