#include <stdio.h>

int main() {
    char str1[20] = "hello"; // str1은 문자열 형태로 초기화
    char str2[20] = {'h','e','l','l','o'}; // str2는 배열 형태로 초기화
    for(int i=0;i<20;i++) {
        printf("%d ",str1[i]);
    }
    printf("\n");
    for(int i=0;i<20;i++) {
        printf("%d ",str2[i]);
    }
    printf("\n");
    return 0;
}