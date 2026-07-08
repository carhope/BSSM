#include <stdio.h>
void st(void){
    static int a =1;
    printf("%d ",a++);
}
void at(void){
    int a=1;
    printf("%d ",a++);
}
int main(void){
    st();
    st();
    st();
    at();
    at();
    at();
    return 0;
}