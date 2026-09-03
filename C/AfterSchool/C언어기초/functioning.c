#include <stdio.h>
int getSum(int scores[],int size){
    int sum=0;
    for (int i=0;i<size;i++){
        sum += scores[i];
    }
    return sum;
}
int getMax(int scores[],int size){
    int max = scores[0];
    for (int i=1;i<size;i++){
        if(scores[i]>max){
            max = scores[i];
        }
    }
    return max;
}
int getAverage(int scores[],int size){
    int count=0;
    double average=0;
    for (int i=0;i<size;i++){
        average += scores[i];
    }
    average = average/size;
    for (int i=0;i<size;i++){
        if (scores[i]>average){
            count++;
        }
    }
    return count;
}
int main(void){
    int scores[5] = {10,20,50,60,70};
    printf("%d",getAverage(scores,5));
    return 0;
}