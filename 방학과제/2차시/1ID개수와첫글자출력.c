#include <stdio.h>
#include <string.h>


int main(){
	int n;
	scanf("%d",&n);
	char abc[100][21]={'\0'}; // 중복되지 않는 ID 배열 처음에 공백으로 초기화
	char cur[21]; // 현재 입력받는 ID
	int checkin=0; // 중복 체크
	int l=0; // 저장된 고유 단어 개수
	for (int i=0;i<n;i++){
		scanf("%s",cur);
		checkin = 0; // 계속 초기화해줌
		for (int j=0;j<l;j++){ // 있는 단어 개수만큼 중복 체크
			if (strcmp(cur ,abc[j])==0){ // strcmp 를 써서 주소가 아닌 문자열을 비교함.
				checkin++;
				break;        // 더이상 더 찾을 필요 없음
			}
		}
		if (checkin == 0){
			strcpy(abc[l],cur);   // strcpy 를 써서 문자열 복사 abc[l]에 cur를 복사함. abc[i]였는데 그렇게 되면 공백이 배열에 들어감. 오류뜸.
			l++;
		}
	}
	printf("%d\n",l);
	for (int k=0;k<=l;k++){      // l개의 문자열이 나와야함
		printf("%s ",abc[k]);
	}
}