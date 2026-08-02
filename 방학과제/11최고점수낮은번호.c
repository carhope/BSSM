#include <stdio.h>
int main(){
    int n;
    int score;
    int lowstu;
    int max=0;
    scanf("%d",&n);
    lowstu=n;
    for (int i=0;i<n;i++){
        scanf("%d",&score);
        if (score > max){
            max = score;
            lowstu= i+1; // lowstu가 0으로 나와 문제였는데 lowstu가 i보다 크면 lowstu = i를 해서 문제였다.
        }
    }
    printf("%d %d",max,lowstu);

}