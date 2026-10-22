#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int queue[MAX];
int qu2[MAX];
int front = -1;
int rear = -1;
int sum;

int isFull(){
    return rear==MAX-1;
}
int isEm(){
    return front==rear;
}

void enq(int da,int ta){
    if (isFull()){
        return;
    }
    rear++;
    queue[rear] = da;
    qu2[rear] = ta;

}

void deq(){
    if (isEm()){
        return;
    }
    front++;
    int tem = queue[front];
    int qu = qu2[front];
    queue[front] = -1;
    qu2[front] = -1;
    sum = sum+qu;
    printf("%d %d\n",tem,sum);
    return;
}
int peek(){
    if (isEm()){
        return -1;
    }
    printf("%d \n",queue[front+1]);
    return queue[front+1];
}
void prq(){
    printf("현재 큐 :");
    for (int i = front+1;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}


int main(){
    int n;

    int da;
    int ta;
    scanf("%d",&n);
    for (int j=0;j<n;j++){
        scanf("%d %d",&da,&ta);
        enq(da,ta);
    }
    for (int j=0;j<n;j++){
        deq();
    }
}