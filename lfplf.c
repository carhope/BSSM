#include <stdio.h>
int main(){
    int i;
    i = 3;
    for (;i==0;)
        if (i%2 == 0) continue;
            printf("%d",i);
            i-=1;   
}