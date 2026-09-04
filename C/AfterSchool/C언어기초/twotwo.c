#include <stdio.h>
int twotwo(int arr[],int size){
    for (int i=0;i<size-1;i++){
        for(int j=1;j<size;j++){
            printf("%d + %d = %d\n",arr[i],arr[j],arr[i]+arr[j]);
        }
    }
}
int main(){
    int n = 4;
    int arr[4]= {3,7,2,5};

    twotwo(arr,n);
}