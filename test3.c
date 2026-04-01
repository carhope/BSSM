//태희가 신청한 전체 학점과 점수를 계산해 신청 학점이 10학점 이상이고, 점수 평균이 4.0을 넘는
//경우 1을 출력하고, 그렇지 않으면 0을 출력하는 프로그램을 작성하세요.
//태희가 신청한 과목당 학점과 얻은 점수는 다음과 같습니다.
//과목
//학점
//점수
//국어
//3학점
//3.8
//영어
//5학점
//4.4
//수학
//4학점
//3.9//
#include <stdio.h>
int main(){
    int kor =3 ,eng =5,math =4;
    int cre = kor +eng+math;
    double ksc,engsc,mathsc,ressc,avg;
    ksc = 3.8;
    engsc = 4.4;
    mathsc = 3.9;
    avg = (ksc+engsc+mathsc)/3.0;
    printf("%d ",cre >= 10&&avg>4.0);

}