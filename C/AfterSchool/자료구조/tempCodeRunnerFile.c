#include <stdio.h>
int countRange(int arr[], int size){
    int count = 0;
    for (int i=0;i<size;i++){
        if (arr[i]>=50 && arr[i]<=80){
            count ++;
        }
    }
    return count;

}

int main(){
    int n = 7;
    int arr[7] = {30,50,72,91,65,80,40};
    int size = 7;
    printf("%d",countRange(arr,size));
}