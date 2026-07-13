#include <stdio.h>
void swap_ptr(char **x, char **y){
    char *temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    char *pa = "cha";
    char *pb = "hiumang";

    printf("pb -> %s, pb -> %s\n",pa,pb);
    swap_ptr(&pa,&pb);
    printf("pa -> %s, pb -> %s\n", pa, pb);
    printf("%c %c",*pb,*pa);
}
