#include <stdio.h>
void max_dist(int arr[],int size){
    int max = 0;
    int dist = 0;
    int cur;
    int x;
    int y;
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            cur = arr[i]-arr[j];
            if (cur<0){
                cur*=-1;
            }
            if(cur > max){
                max = cur;
                x = arr[i];
                y= arr[j];
            }
        }
    }
    printf("%d %d\n%d",x,y,max);
}
int main(){
    int n=5;
    int arr[5]= {8,3,15, 6 ,10};
    max_dist(arr,n);
}