#include <stdio.h>
int main(){
    int a =30;
    int res;

    res =(a>10)&&(a<20);
    printf("%d\n",res);
    res =(a<10)||(a>20);
    printf("%d\n",res);
    res = !(a >= 30);
    printf("%d\n",res);
}