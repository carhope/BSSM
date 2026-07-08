#include <stdio.h>

struct profile{
    int age;
    double height;
};

struct student{
    struct profile pf;
    int id;
    char *name;
    double grade;
};

int main(){
    struct student s1;
    s1.pf.age = 17;
    s1.pf.height = 165.2;
    s1.id = 312;
    s1.name = "Jane Doe";
    s1.grade = 3.74;
    printf("agge : %d\n",s1.pf.age);
    printf("height : %.1lf\n", s1.pf.height);
    printf("id : %d\n",s1.id);
    printf("name : %s\n",s1.name);
    printf("grade : %.2lf\n",s1.grade);
}