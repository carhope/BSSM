'''다음과 같은 n*m 배열 구조를 출력해보자.

입력이 3 4인 경우 다음과 같이 출력한다.
1 2 4 7
3 5 8 10
6 9 11 12

입력이 4 5인 경우는 다음과 같이 출력한다.
1 2 4 7 11
3 5 8 12 15
6 9 13 16 18
10 14 17 19 20

입력이 n m인 경우의 2차원 배열을 출력해보자.'''

n, m = map(int, input().split())

arr = [[0] * m for _ in range(n)]

num = 1

for s in range(n + m - 1):
    for i in range(n):
        j = s - i

        if 0 <= j < m:
            arr[i][j] = num
            num += 1

for row in arr:
    print(*row)