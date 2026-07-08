#include <stdio.h>
#define MUL(a,b) (a*b)
#define SUB(a,b)(a-b)
#define SWAP(a,b) {int temp =a; a=b; b= temp;} // 매크로 함수

int main(){
    int a= 20, b= 10;
    printf("SUB : %d\n",SUB(a,b));
    printf("PRODUCT: %d\n",400/MUL(a,b));
    SWAP(a,b);
    printf("swap_SBU: %d\n",SUB(a,b));
}