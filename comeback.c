#include <stdio.h>
int sum(int x, int y);
int main(void){
    int a,b;
    int result;

    scanf("%d%d",&a,&b);
    result = sum(a,b);
    printf("a + b = %d",result);
    return 0;
}
int sum(int x, int y){
    return x+ y;
}