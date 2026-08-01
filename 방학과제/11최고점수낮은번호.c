#include <stdio.h>
int main(){
    int n;
    int score;
    int lowstu;
    int max=0;
    int befo=0;
    scanf("%d",&n);
    lowstu=n;
    for (int i=0;i<n;i++){
        scanf("%d",&score);
        if (score > max){
            max = score;
            if (befo > max){
                befo=max;
                if (i<lowstu){
                    lowstu = i-1;
                }
            }
        }
    }
    printf("%d %d",max,lowstu);

}