#include <stdio.h>
void sum10(int arr[],int size){
    for (int i=0;i<size-1;i++){
        for (int j=1;j<size;j++){
            if (arr[i]+arr[j] == 10 && i!=j && i<j){
                printf("%d %d\n",arr[i],arr[j]);
            }
        }
    }
}
int main(){
    int n=6;
    int arr[6]= {3,7,2,8,5,1};
    sum10(arr,n);
    return 0;
}