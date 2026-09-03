#include <stdio.h>

int main(){
    int age;
    printf("점수를 입력하세요 : ");
    scanf("%d",&age);
    if (age>=17){
        printf("입장 가능");
    }
    else{
        printf("입장 불가");
    }
}