#include <stdio.h>
int printRectangle(int x,int y){
    for (int i=1;i<x+1;i++){
        for (int j=1;j<y+1;j++){
            printf("%d",j);
        }
        printf("\n");
    }
}
int main(){
    int x=3;
    int y=5;

    printRectangle(x,y);
}