#include <stdio.h>
#include <string.h>

struct studentdata
{
    char names[5][20];
    int scores[5];
};

int main(){
    struct studentdata sd;
    for (int i=0;i<5;i++){
        printf("Name : ");
        scanf("%s",sd.names[i]);
        printf("Score : ");
        scanf("%d",&sd.scores[i]);
    }
    int avg = 0;
    for (int k=0;k<5;k++){
        avg = avg+sd.scores[k];
    }
    avg = avg/5;
    printf("%d\n",avg);
    for (int j=0;j<5;j++){
        if (sd.scores[j] >= 80){
            printf("%s %d\n",sd.names[j],sd.scores[j]);
        }
    }
}