#include <stdio.h>

struct score{
    int kor;
    int eng;
    int math;
};

int main(){
    struct score s= {90,80,70};
    struct score *ptr = &s;

    printf("kor : %d\n", (*ptr).kor);
    printf("eng : %d\n",ptr->eng);
    printf("math : %d\n",ptr->math);
}