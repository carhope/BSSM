#include <stdio.h>

#define SIZE 21

int queue[SIZE];
int front = 0;
int rear = 0;

int isEmpty(void){
    return rear==front;
}
int isFull(){
    return (rear+1)%SIZE==front;
}
int enqueue(int value){
    if (isFull()){
        return 0;
    }
    rear=rear+1;
    queue[rear] = value;
    return 1;
}
int dequeue(){
    if (isEmpty()){
        return 0;
    }
    front = front+1;
    return queue[front];
}
int peek(void){
    return queue[(front+1)%SIZE];
}
void printQueue(void){
    if(isEmpty()){
        printf("큐가 비어있습니다");
        return;
    }
    int i = (front+1)%SIZE;
    printf("큐 : ");
    while(1){
        printf("%d ",queue[i]);
        if(i==rear){
            break;
        }
        i = (i+1)%SIZE;
    }
    printf("\n");
}
int main(){
    int n;
    int allcount;
    int arr[SIZE];
    int cur;
    int count = 1;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        allcount+=arr[i];
    }
    enqueue(arr[0]);
    while (!isEmpty()){
        cur = dequeue()-1;
        if(cur>0){
            printf("%d",cur-1);
        }
        else{
            printf("DONE");
        }
    }
}