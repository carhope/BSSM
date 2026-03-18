#include <stdio.h>
int main(){
    int arr[3];
    int* ptr =arr;
    

    *(arr+0)=10;
    *(arr+1)=*(arr +0)+10;

    printf("세 번째 배열 요소에 키보드 입력 : ");
    scanf("%d",arr+2);
    printf("arr 0번방 : %d\n", *(ptr++));
    printf("arr 1번방 : %d\n", *(ptr++));
    printf("arr 2번방 : %d\n", *(ptr));
}
