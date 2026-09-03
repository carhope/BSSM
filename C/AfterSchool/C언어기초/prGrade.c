#include <stdio.h>
int printGrade(int arr[],int size){
    for (int i=0;i<size;i++){
        if(arr[i]>=90){
            printf("A ");
        }
        else if(arr[i]>=80){
            printf("B ");
        }
        else if(arr[i]>=70){
            printf("C ");
        }
        else{
            printf("D ");
        }
    }
    return 0;
}
int main(){
    int n=5;
    int arr[5]={95,83,72,68,90};

    printGrade(arr,n);
}