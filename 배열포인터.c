#include <stdio.h>

void print_ary(int (*pa)[4]){
    int i,j;
    for (i=0;i<3;i++){
        for (j=0;j<4;j++){
            printf("%4d",pa[i][j]);
        }
    }
    printf("\n");
}
int main(){
    int ary [3][4]={{1,2,3,4},{4,5,6,7},{7,8,9,10}};
    int (*pa)[4] =ary;
    print_ary(ary);
    return 0;
    
}