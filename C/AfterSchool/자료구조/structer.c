#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; //노드를 가릴 킬거기 때문에 노드 주소로 선언한다.
};
struct Node* insertFront(struct Node* head, int data){
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode-> data = data;
    newNode->next = head;
    head = newNode;
    return head;
}
void printList(struct Node* head){
    struct Node* current = head;

    while (current != NULL){
        printf("%d ",current->data);
        current = current->next;
    }
}
struct Node* search(struct Node* head, int target){
    struct Node* current = head;
    while (current != NULL){
        if (current->data == target){
            return current;
        }
        current = current->next;
    }
    return NULL;
}
int main(){

    //NewNode = malloc(sizeof(struct Node)); // 구조체 선언한다고 메모리 안줘서 동적할당(생성해서 첫 주소 반환)
    struct Node* head=NULL;
    head = insertFront(head,30);
    head = insertFront(head,40);
    head = insertFront(head,50);
    head = insertFront(head,60);
    head = insertFront(head,70);
    printList(head);
}