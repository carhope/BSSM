#include <stdio.h>
int main(){
    double a;
    int b;
    a = 5.0/2.0;
    b = 5/2;
    printf("A : %.1f\n",a);
    printf("B : %d\n",b);

    a = 5/2.0;
    b =5.0 /2;
    printf("A : %.1f\n",a);
    printf("B : %d\n",b);
    printf("5/2: %.1f\n",(float)5/2);
    return 0;
}