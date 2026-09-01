#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Noee* next;
}Node;

void insertBack(Node** head, int data){
    Node* newNode = malloc(sizeof(Node));

    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL){
        *head = newNode;
        return;
    }
    Node* current = *head;

    while(current->next!=NULL){
        current=current->next;
    }
    current->next= newNode;
}

Node* linearSearch(Node* head, int target){
    Node* current = head;
    while (current != NULL){
        if (current->data == target){
            return current;
        }
        current = current -> next;
    }
    return NULL;
}

int main(void){
    Node* head = NULL;
    insertBack(&head,17);
    insertBack(&head,8);
    insertBack(&head,25);
    insertBack(&head,31);
    insertBack(&head,12);
    insertBack(&head,40);
    insertBack(&head,6);

    int target;

    printf("찾을 숫자 : ");
    scanf("%d",&target);

    Node* result = linearSearch(head,target);
    if (result!=NULL){
        printf("%d를 찾았습니다",target);
    }
    else{
        printf("%d를 못찾음",target);
    }
    Node* current = head;

    while (current != NULL){
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;

}