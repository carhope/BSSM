#include <stdio.h>
void hello(int n);

int main(){
    hello(5);
    return 0;
}

void hello(int n){
    if (n==0){
        return;
    }
    else{
    printf("훌레 딱");
    hello(n-1);
    }
    printf("hi");
}