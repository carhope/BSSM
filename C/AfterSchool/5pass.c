#include <stdio.h>
int main(){
    int score;
    scanf("점수 : %d",&score);
    if (score>=70){
        printf("aim : 70 So : %d PASS",score-70);
    }
    else{
        printf("%d 점 부족함 FAIL",70-score);
    }
}