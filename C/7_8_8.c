#include <stdio.h>

struct list{
    int num;
    struct list *next;
};

int main(){
    struct list a = {10,NULL}, b = {20,NULL}, c= {30,NULL};
    struct list *head = &a, *current;

    a.next = &b;
    b.next = &c;

    printf("list all : ");
    current = head;
    while (current != NULL){
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");
    return 0;
}