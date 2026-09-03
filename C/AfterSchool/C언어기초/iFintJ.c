#include <stdio.h>

int sumEvenOver10(int arr[], int size){
    int sum = 0;
    for (int i=0;i<size;i++){
        if(arr[i]>=0 && arr[i]>10 && arr[i]%2 == 0){
            sum+=arr[i];
        }
    }
    return sum;
}
int main(){
    int n = 6;
    int arr[6] = {5,12,8,20,15,30};

    printf("%d",sumEvenOver10(arr,n));
}