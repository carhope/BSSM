#include <stdio.h>

#define SIZE 5

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
    int userin;
    int data;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d",&userin);
        if(userin==1){
            scanf("%d",&data);
            if(!isFull()){
                enqueue(data);
                printf("ADDED");
            }
            else{
                printf("FULL");
            }
        }
        else if(userin==2){
            if(!isEmpty()){
                printf("%d",dequeue());
            }
            else{
                printf("EMPTY");
            }
        }
        else if(userin == 3){
            if(!isEmpty()){
                printQueue();
            }
            else{
                printf("EMPTY");
            }
        }
    }
}