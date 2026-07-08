#include <stdio.h>
int main(){
    char str[100];
    int a;
    scanf("%d", &a);
    scanf("%[^\n]",str);
    printf("%s",str);
    
}