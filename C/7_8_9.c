#include <stdio.h>

typedef struct list{
    int num;
    struct list *next;
}List;

int main(){
    List a= {10,NULL}, b = {20,NULL}, c ={30,NULL};
    List *head = &a, *current;

    a.next = &b;
    b.next = &c;

    printf("list all : ");
    current = head;
    while(current != NULL){
        printf("%d ", current -> num);
        current = current->next;
    }
    printf("\n");
    return 0;
}