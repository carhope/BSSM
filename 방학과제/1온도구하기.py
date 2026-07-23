'''하루동안 측정한 온도 N개 정상 온도는 L 이상 R이하.
정상온도 보다 낮은온도와 높은 온도의 개수 각각 구하기
입력 형식 : 첫줄에 측정 횟수 N,정상범위의 최솟값 L, 정상 범위의 최대값 R이 공백으로
두째줄 측정한 온도 N개
출력 : 정상 온도 보다 낮은 온도 개수 높은 온도 개수 각각 공백으로 출력'''

n,L,R = map(int,input().split(' '))
all = []
lnum = []
rnum = []

all = list(map(int, input().split(' ')))

for k in all:
    if k < L:
        lnum.append(k)
    elif k > R:
        rnum.append(k)

print(len(lnum),len(rnum))