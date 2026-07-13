#include <stdio.h>
int main(){
    int ary1[4] = {11,22,33,44};
    int ary2[4] = {21,23,35, 41};
    int ary3[4] = {31, 12,16, 17};
    int ary4[4] = {35,19,12,19};
    int *ptr[3] = {ary1,ary2,ary3,ary4};
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            printf("%5d",ptr[i][j]);
        }
        printf("\n");
    }
}