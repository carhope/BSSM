#include <stdio.h>
int linearSearch(int arr[],int size, int target){
    int count=0;
    for (int i=0;i<size;i++){
        count++;
        if (arr[i]==target){
            return i;
        }
        printf("%d ",i);
    }
    printf("총 비교 횟수 : %d번\n",count);
    return -1;
}

int main(void){
    int arr[] = {13,8,27,4,19};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;

    printf("찾을 숫자 입력 : ");
    scanf("%d",&target);

    int result = linearSearch(arr,size,target);

    if (result == -1){
        printf("%d는 배열에 없습니다",target);
    }
    else{
        printf("%d는 인덱스 %d번째에 있습니다",target,result);
    }
    return 0;
}