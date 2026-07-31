#include <stdio.h>
int main() {
	int n,curlen=0;
	int maxcur=0;
	char input[100];
	char maxstring[100];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",input);
		curlen=0;
			for (int k=0;input[k]!='\0';k++){ //실행해서 결과가 0이 나오길래 봤더니 그냥 k!='\0' 라고 조건문이 적혀있었다. 멍청이 같은 실수와 싸우는게 개발자 인거같다. 하지만 이제 그 멍청이 같은 실수는 AI가 잘 찾는거같다.
				curlen++;
			}
		if (curlen > maxcur){
			    int i;

	    for (i = 0; (maxstring[i] = input[i]) != '\0'; i++) {

			}
			maxcur = curlen;
		}
	}
	printf("%s %d",maxstring,maxcur);
	return 0;
}