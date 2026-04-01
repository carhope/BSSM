//두 과목의 점수를 입력해 평균을 출력하는 프로그램을 완성할 수 있도록 빈 칸에 알맞은 수식을
//적으시오. 단, 평균은 소수점 이하 첫째 자리까지 출력하시오.
#include <stdio.h>
int main(void) {
    int a, b, tot;
    double avg;

    printf("두 과목의 점수 : ");

    scanf("%d %d", &a, &b);
    tot = a + b;
    avg = tot /2.0; //몇으로 나누어야 할지 생각해보기
    printf("평균 : %.1f \n", avg);
    return 0;
}
//입력
//출력
////없음
//두 과목의 점수 : 70 85
//평균 : 77.5