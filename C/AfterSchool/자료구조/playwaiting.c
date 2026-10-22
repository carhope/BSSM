#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct player{
    int pnum;
    int ptall;
};
struct player queue[MAX];
int front = -1;
int rear = -1;

int isFull(){
    return rear==MAX-1;
}
int isEm(){
    return front==rear;
}

void enq(struct player data){
    if (isFull()){
        return;
    }
    rear++;
    queue[rear] = data;

}

struct player deq(){
    if (isEm()){
        struct player empty = {-1, -1};
        return empty;
    }
    front++;
    struct player tem = queue[front];
    queue[front].pnum = -1;
    queue[front].ptall = -1;
    printf("%d \n",tem.pnum);
    return tem;
}
int peek(){
    if (isEm()){
        return -1;
    }
    printf("%d \n",queue[front+1].pnum);
    return queue[front+1].pnum;
}
void prq(){
    printf("현재 큐 :");
    for (int i = front+1;i<=rear;i++){
        printf("%d ",queue[i].pnum);
    }
    printf("\n");
}
int main(){
    int n,k,h;
    int num,tall;
    int count=0;
    scanf("%d %d %d",&n,&k,&h);
    for (int i=0;i<n;i++){
        scanf("%d %d",&num,&tall);
        struct player player;
        player.pnum = num;
        player.ptall = tall;
        enq(player);
    }
    for (int i=0;i<n;i++){
        struct player de = deq();
        if (count>=k){
            printf("%d",i-(n-1));
            break;
        }
        if (de.ptall >= tall){
            printf("%d ",de.pnum);
            count ++;
        }

    }
}