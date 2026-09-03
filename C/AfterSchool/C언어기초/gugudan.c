#include <stdio.h>
int gugudan(int one,int two){
    int fromend = two-one;
    for (int i=0;i<=fromend;i++){
        int cur = one+i;
        printf("구구단 %d단 \n",cur);
        for (int i=1;i<10;i++){
            printf("%d x %d = %d \n",cur,i,cur*i);
        }
    }

}
int main(){
    gugudan(3,4);
}