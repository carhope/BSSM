/* 교통 이용 횟수 n 입력/ 하루 상한액 c 입력
실제 결제액, 할인액 출력
*/
#include <stdio.h>

int main(){
    int n,c;
	scanf("%d %d", &n, &c);
	int oneday,result;
	result=0;
	for (int i=0;i<n;i++){
		scanf("%d",&oneday);
		result = result+oneday;
	}
	if (result>c){
		printf("%d %d",c, result-c);
	}
	else{
		printf("%d 0", result);
	}
}