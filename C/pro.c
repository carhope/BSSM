#include <stdio.h>
int main(){
    int a;
    int* ptr;
    ptr =&a;
    *ptr =10;

    
    printf("포인터로 a값 출력 : %d\n", *ptr);
    printf("변수명으로 a값 출력 : %d\n", a);
    printf("포인터 ptr의 값 : %p\n", ptr);
    printf("변수 a의 주소: %p\n", &a);
}