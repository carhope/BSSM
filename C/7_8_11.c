#include <stdio.h>

 typedef struct list* listptr;
 typedef struct list{
    int num;
    listptr next;
 }list;
 
 int main(){
    list a = {10,NULL}, b = {20,NULL}, c = {30, NULL};
    listptr head = &a;
    listptr cur;
    
    a.next = &b;
    b.next = &c;
    printf("head->num : %d\n",head->num);
    printf("head->next->num : %d\n",head->next->num);

    cur = head;
    while(cur!=NULL){
        printf("%d ", cur->num);
        cur = cur->next;
    }
 }