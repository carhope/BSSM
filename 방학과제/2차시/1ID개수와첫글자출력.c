#include <stdio.h>
#include <string.h>


int main(){
	int n;
	scanf("%d",&n);
	char abc[100][21]={'\0'};
	char cur[21];
	int checkin=0;
	int l=0;
	for (int i=0;i<n;i++){
		scanf("%s",cur);
		checkin = 0;
		for (int j=0;abc[j]!='\0';j++){
			if (cur == abc[j]){
				checkin++;
			}
		}
		if (checkin == 0){
			strcpy(abc[i],cur);
			l++;
		}
	}
	printf("%d\n",l);
	for (int k=0;abc[k]!='\0';k++){
		printf("%c",abc[k]);
	}
}