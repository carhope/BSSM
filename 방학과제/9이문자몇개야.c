#include <stdio.h>
int main() {
	char input[1000];
	char aimc[2];
	int aimtoaim=0;
	scanf("%s",input);
	scanf("%s",aimc);
	for(int i=0;input[i]!='\0';i++){
		if (input[i]==aimc[0]){// 실행해도 원하는 결과가 안나오길래 봤더니 aimc라고 되어있었다. 그래서 aimc[0]으로 고쳤다 왜냐면 aimc하면 전체 문자열을 말하는 거여서 원하는 문자 하나만 말하는게 아니다. 그래서 같지 않다고 하여 aimtoaim이 오르지 않았던것이다.
			aimtoaim++;
		}
	}
	printf("%d",aimtoaim);
	return 0;
}
