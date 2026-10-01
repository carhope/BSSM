#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10

char stack[MAX_SIZE];
char top=-1;

void push(int value){
    if (top==MAX_SIZE-1){
        printf("FULL");
        return;
    }
    top++;
    stack[top]=value;
}
char pop(){
    if(top==-1){
        printf("nothing");
        return '1';
    }
    char value = stack[top];
    top--;
    return value;
}

int main(){
    char str[MAX_SIZE];
    scanf("%s",str);
    int valid = 1;
    for (int i=0;i<strlen(str);i++){
        if (str[i]=='('){
            push('(');
        }
        else if(str[i]==')'){
            if(top==-1){
                valid=0;
                break;
            }
            pop();
        }
    }
    if(top!=-1){
        valid = 0;
    }
    if(valid){
        printf("YES");
    }
    else{
        printf("NO");
    }
}