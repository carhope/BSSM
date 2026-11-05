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
    int userin=1;
    int data;
    while(userin != 0){
        printf("1. 삽입\n2. 삭제 \n3. 다음삭제대상 \n4. 전체 출력 \n0.종료 : ");
        scanf("%d",&userin);
        if(userin==1){
            printf("삽입할 데이터 : ");
            scanf("%d",&data);
            if(enqueue(data)){
                printf("삽입 성공\n");
                continue;
            }
            else{
                printf("큐가 가득 찼습니다\n");
            }
        }
        else if(userin==2){
            if(dequeue() != 0){
                printf("삭제한 데이터 %d\n",dequeue());
                continue;
            }
            else{
                printf("큐가 비었습니다\n");
            }
        }
        else if(userin == 3){
            if(!isEmpty()){
                printf("다음 삭제할 대상 : %d\n",peek());
                continue;
            }
            else{
                printf("삭제할 대상 없음\n");
            }
        }
        else if(userin == 4){
            if (!isEmpty()){
                printQueue();
            }
        }
        else if (userin == 0){
            printf("종료합니다");
            break;
        }
        else{
            printf("다시 입력해");
            continue;
        }
    }
}