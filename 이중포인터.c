#include <stdio.h>
int main(){
    int a =10;
    int *pi;
    int **ppi;

    pi = &a;
    ppi = &pi;

    printf("a : %12d %12p\n",a, &a);
    printf("pi : %12p %12p %12d\n", pi, &pi, *pi);
    printf("ppi : %12p %12p %12p %12d", ppi,&ppi,*ppi,**ppi);
}