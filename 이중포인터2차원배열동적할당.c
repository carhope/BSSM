#include <stdio.h>
#include <stdlib.h>
//2차원 배열처럼 생긴것이지 1차원 배열을 묶어둔것임.
int main(){
    int i,j,n,cnt = 1;
    scanf("%d",&n);
    int **arr = (int **)malloc(sizeof(int *) *n);
    for(i=0;i<n;i++){
        arr[i]=(int *)malloc(sizeof(int )* n);
    }
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            arr[i][j]=cnt++;
        }
    }
    for (i =0;i<n;i++){
        for (j=0;j<n;j++){
            printf("%4d", *(*(arr+i)+j));
        }
        printf("\n");
    }
    for (i=0;i<n;i++){
        free(arr[i]);
    }
}