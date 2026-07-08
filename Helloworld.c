#include <stdio.h>
int main(){
    char str1[20]="Hello";
    char str2[20]={'H','e','l','l','o'};
    for (int i =0;i<20;i++){
        printf("%d ",str1[i]);
    }
    
printf("\n");
for (int i=0;i<20;i++){
    printf("%d ", str2[i]);
}

}