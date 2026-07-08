#include <stdio.h>

struct student{
    char a;
    long long b;
    char c;
};

int main(){
    struct student s1;
    printf("%d\n", sizeof(s1.a));
    printf("%d\n", sizeof(s1.b));
    printf("%d\n", sizeof(s1.c));
    printf("%d", sizeof(s1));

    return 0;
}