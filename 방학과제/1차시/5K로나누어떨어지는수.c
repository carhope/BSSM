#include <stdio.h>
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int storage;
    int total=0;
    for (int i=0;i<n;i++){
        scanf("%d",&storage);
        if (storage%k==0){
            total++;
        }
    }
    printf("%d",total);
}