#include <stdio.h>
/* 하기전 구상
N일 입력 받기
n개의 공부여부 받기
굳이 배열에 넣어야하는가?
ㄴㄴ 
변수 int cur -> 현재 공부 여부를 받는다
변수 int start - > 공부 시작일 -> for 문이 돌아가면서 cur을 받는데 i를 +1 해서 start를 설정한다.
변수 int deadline -> 공부 종료일 -> for 문이 돌아가면서 cur을 받는데 0이면 i로 설정한다.
변수 int longest -> 최대 공부일 -> curlong이 long보다 크면 curlong으로 설정
변수 int curlong -> 현재 연속 공부일 -> cur
for (int i=0;i<n;i++){

cur이 만약 0이라면
if curlong!=0 && deadline < curlong:
deadline = i
-> curlong = 0

cur 이 만약 1이라면
-> curlong ++
if curlong==0 && start < curlong:
start = i+1
if curlong > longest:
longest = curlong*/
int main(){
    int n;
    scanf("%d",&n);
    int cur;
    int start=0;
    int deadline = 0;
    int curlong=0;
    int longest = 0;
    for (int i=0;i<n;i++){
        scanf("%d",&cur);
        if (cur == 0){
            if (curlong !=0 && deadline < curlong){
                deadline = i;
            }
            curlong = 0;
        }
        if (cur == 1){
            curlong++;
            if (curlong<=1){
                start = deadline - (longest-1);
            }
            if (curlong > longest){
                longest = curlong;
            }
        }
    }
    printf("%d %d %d",longest,start,deadline);
    

}