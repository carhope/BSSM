#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;
int in;
int done = 0;

int isFull() {
    return rear == MAX - 1;
}

int isEm() {
    return front == rear;
}

void enq(int data) {
    if (isFull()) {
        return;
    }
    rear++;
    queue[rear] = data;
}

int deq() {
    if (isEm()) {
        return -1;
    }
    front++;
    int tem = queue[front];
    queue[front] = -1;
    return tem;
}

int main() {
    scanf("%d", &in);
    enq(in);

    while (!isEm()) {
        int x = deq();

        if (front > 0) {
            printf(" ");
        }
        printf("%d", x);

        if (x == 1) {
            done++;
        } else {
            int first = x / 2;
            enq(first);
            enq(x - first);
        }
    }

    printf("\n%d\n", done);

    return 0;
}