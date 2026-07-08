#include <stdio.h>
int main(){
	int M, N;
	int r = 0;
	int result =0;
	int f=0;
	int isprime;
	scanf("%d",&M);
	scanf("%d",&N);
	for (int i=M;i<=N;i++){
		if (i<2)continue;
		int isprime=1;
		for (int j=2;j*j<=i;j++){
			if(i%j==0){
				isprime=0;
				break;
			}
			}
		
		if (isprime==1){
			if(result==0){
				result=i;
			}
			for (int k=2;k<=i;k++){
				for (int o=2;o*o<=i;o++){
					f=f+o;
				}
			}
		}
	}
	if(result==0 && f==0){
		printf("-1");
	}
	else{
	printf("%d\n",f);
	printf("%d",result);
	}
}