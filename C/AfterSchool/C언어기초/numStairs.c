#include <stdio.h>
int numST(int num){
    int count = 2;
    for (int i=1;i<num+1;i++){
        for (int j=1;j<count;j++){
            printf("%d",j);
        }
        printf("\n");
        count++;
    }
}
int main(){
    numST(5);
}
