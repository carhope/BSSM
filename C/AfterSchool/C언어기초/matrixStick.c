#include <stdio.h>
void matrixStick(int arr[], int size){
    for (int i=0;i<size;i++){
        for (int j=0;j<arr[i];j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    int size=5;
    int arr[5]={3,1,4,2,5};
    matrixStick(arr,size);
}