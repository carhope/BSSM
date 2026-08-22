/* 행 r, 열 c, 찾아야할 번호 k 입력
k가 있는 행과 열 출력
2차원 배열사용
각각 들어갈 번호 저장 curr*/
#include <stdio.h>
int main(){
    int r,c,k,num;
    scanf("%d %d %d",&r, &c,&k);
    int curr= 1;
    int arr[r][c];
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            arr[i][j]=curr;
            curr++;
        }
    }
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            if (arr[i][j]==k){
                printf("%d %d",i+1,j+1);
            }
        }
    }
}