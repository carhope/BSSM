#include <stdio.h>
void matrixStick(int size, int arr[]){
    for (int i=0;i<size;i++){
        for (int i=0;i<arr[i];i++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int size=5;
    int arr[5]={3,1,4,2,5};
    matrixStick(size,arr);
}