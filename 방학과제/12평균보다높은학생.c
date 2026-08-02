#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	int scores[101];
	int upperstu=0;
	int avg = 0;

	for (int i=0; i<n;i++){
		scanf("%d",&scores[i]);
	}
	for (int i=0;i<n;i++){
		avg = avg+scores[i];
	}
	avg = avg/n;

	for (int j=0;j<n;j++){
		if (scores[j]>avg){
			upperstu++;
		}
	}
	printf("%d",upperstu);
}