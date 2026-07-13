#include <stdio.h>
int swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    return 0;

}
int main(){
    int x=10,y=211;
    printf("swap 함수 호출 전 : a =%d,b = %d\n",x,y);
    swap(&x,&y);
    swap(&x,&y);
    printf("swap 함수 호츨 후 : a =%d,b = %d\n",x,y);

    return 0;
}