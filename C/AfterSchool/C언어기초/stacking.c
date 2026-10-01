#include <stdio.h>

#define MAX_SIZE 10
int stack[MAX_SIZE];
int top=-1;

void push(int value){
    if (top >= MAX_SIZE-1){
        printf("응 꽉찼어");
        return;
    }
    top++;
    stack[top] = value;
}
int pop(){
    if (top==-1){
        printf("응 아무것도 없는데 뭘 가져올까");
        return 0;
    }
    int value = stack[top];
    top--;
    return value;

}
int peek(){
    if (top==-1){
        printf("응 없어");
    }
    int value = stack[top];
    return value;
}

int main(){
    int user;
    int x;
    while (user!=5){
        scanf("%d",&user);
        if (user==1){
            scanf("%d",&x);
            push(x);
        }
        else if(user==2){
            printf("%d",pop());
        }
        else if(user==3){
            printf("%d",peek());
        }
        else if(user==4){
            printf("%d",top+1);
        }

    }
}