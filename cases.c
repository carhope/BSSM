#include <stdio.h>
int main(){
    char ch;
    printf("영어 소문자 입력하세요 : ");
    scanf("%c", &ch);
    switch (ch){
        case 'a' : printf("모음"); break;
        case 'e' : printf("모음"); break;
        case 'i' : printf("모음"); break;
        case 'o' : printf("모음"); break; 
        case 'u' : printf("모음"); break;
        default : printf("자음"); break;
    }
}