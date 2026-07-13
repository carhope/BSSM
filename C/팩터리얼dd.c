#include <stdio.h>

long long fact(int n){
    if (n ==1)return 1;
    else {
        return n *fact(n-1);
    }
}
int main(void){
    long long f;
    int n;
    scanf("%d",&n);
    f = fact(n);
    printf("%lld",f);
    return 0;
}