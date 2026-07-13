#include <stdio.h>

struct student {
    int num;
    char name[20];
    double grade;
};

int main(){
    struct student s1;
    scanf("%d",&s1.num);
    scanf("%s",s1.name);
    scanf("%lf",&s1.grade);
    printf("num : %d\n", s1.num);
    printf("name : %s\n",s1.name);
    printf("grade : %.1f\n", s1.grade);

    return 0;
}