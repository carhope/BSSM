#include <stdio.h>
int main(void){
	int n;
	scanf("%d\n",&n);
	
	int arr[100]={0};
	int x,y;
	scanf("%d %d",&x,&y);
	int xx,yy;
	for (int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            xx = i-x;
            yy = j-y;
            if (xx <0){
                xx = xx*-1;
            }
            if (yy<0){
                yy = yy*-1;
            }
            arr[j-1] = xx+yy+1;
            printf("%d ",arr[j-1]);
        }
        printf("\n");
    }
}