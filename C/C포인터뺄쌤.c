#include <stdio.h>
int main(void){
    int a[5] = {10,20,30,40,50};
    int *ptr = a;
    int *ptr2 = a+3;
    printf("%ld\n",ptr2-ptr);
    if (ptr2>ptr){
        printf("ptr2 > ptr");
    
    }
    else {
        printf("ptr2<=ptr");
    }
}