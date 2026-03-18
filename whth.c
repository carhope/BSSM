#include <stdio.h>
int main(){
    char a;
    scnaf("선생님이 기침을 하면?%c",&a);
    if(a == "세미콜론"){
        printf("정답!!ㅋㅋㅋㅋ")
    }

    else{
        printf("세미콜론 엌ㅋㅋㅋㅋ 이걸 몰라 ㅋㅋㅋ%c는 뭘깤ㅋㅋㅋㅋ",a);
    }
}
