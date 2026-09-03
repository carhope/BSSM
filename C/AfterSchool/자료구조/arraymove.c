#include <stdio.h>

int main(){
    int arr[10] = {10,20,30,40,50};
    int size = 5;
    int index =2;
    int value= 25;

    for (int i = size; i>index-1; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = value;
    size++;

    for (int i=0; i<size;i++){
        printf("%d ",arr[i]);
    }
}