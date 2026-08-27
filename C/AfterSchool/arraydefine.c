#include <stdio.h>
int arr[10] = {10,20,30,40,50};
int del(int index,int size){
    
    for (int i=index;i<size-1;i++){
        arr[i] = arr[i+1];
    }
    size--;
    return size;
    
}

int inser(int index,int value,int size){
    for (int i=size+1;i>index;i--){
        arr[i] = arr[i-1];
    }
    arr[index] = value;
    size++;
    return size;
}
int main(){
    
    int size=5;
    int index;
    int value;
    printf("현재 배열");
    for (int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    int input;
    while (input != 0){
        printf("0 종료, 1 삽입, 2 삭제, 3 배열보기");
        scanf("%d",&input);
        if (input==0){
            break;
        }
        else if (input == 1){
            printf("삽입할 인덱스와 값 : ");
            scanf("%d %d", &index,&value);
            inser(index,value,size);
        }
        else if (input == 2){
            printf("삭제할 인덱스 : ");
            scanf("%d",&index);
            del(index,size);
        }
        else if (input == 3){
            for (int i=0;i<10;i++){
                printf("%d ",arr[i]);
            }
            printf("\n");
        }
    }
}