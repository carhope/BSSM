#include <stdio.h>
int main(){
    int n,in;
    int plus=0,minus=0,zero=0;
    scanf("%d",&n);

    for (int i=0;i<n;i++){
        scanf("%d",&in);
        if (in==0){
            zero++;
        }
        else if (in>0){
            plus++;
        }
        else{
            minus++;
        }
    }
    printf("%d %d %d",plus,minus,zero);
}