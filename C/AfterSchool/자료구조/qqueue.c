#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1
;
int isFull(){
    return rear==MAX-1;
}
int isEm(){
    return front==rear;
}

void enq(int data){
    if (isFull()){
        return;
    }
    rear++;
    queue[rear] = data;

}

int deq(){
    if (isEm()){
        return -1;
    }
    front++;
    int tem = queue[front];
    queue[front] = -1;
    printf("%d \n",tem);
    return tem;
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
    enq(5);
    enq(8);
    enq(3);
    deq();
    deq();
    prq();
}