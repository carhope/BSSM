#include <stdio.h>
#define PI 3.14159 //매크로 정의 : 치환식 소멸임 ( 메모리 공간 X)
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("Exceed limits\n")

int main(){
    double radius, area;
    printf("input radius : ");
    scanf("%lf",&radius);
    area = PI *radius * radius;
    if (area>LIMIT) ERR_PRN;
    else printf("circle area : %.2lf (%s)\n",area, MSG);
}