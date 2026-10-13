#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int target;
    scanf("%d",&target);
    for (int j=0;j<n;j++){
        if(arr[j]==target){
            printf("%d",j+1);
        }
    }
}