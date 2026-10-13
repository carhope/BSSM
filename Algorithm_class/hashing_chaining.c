#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 5

struct Node {
    int key;
    struct Node *next;
};

struct Node *table[TABLE_SIZE];

int hash(int key){
    return key% TABLE_SIZE;
}
void insert(int key){
    int index = hash(key);
    struct Node *newNode = malloc(sizeof(*newNode));
    if (newNode == NULL) return;
    newNode -> key = key;
    newNode->next=table[index];
    table[index]=newNode;
}
struct Node * Search(int key){
    int index = hash(key);
    struct Node * current = table[index];
    while(current!=NULL){
        if(current->key==key){
            return current;
        }
        current = current->next;
    }
    return NULL;
}
void delete(int key){
    int index = hash(key);
    struct Node * prev = NULL;
    struct Node * current = table[index];
    while(current!=NULL && current->key != key){
        prev=current;
        current = current->next;
    }
    if(current == NULL){
        return;
    }
    if(prev==NULL){
        table[index]=current->next;
    }
    else{
        prev->next=current->next;
    }
    free(current);
}
void freetable(){
    for (int i=0;i<TABLE_SIZE;i++){
        struct Node * current = table[i];
        while(current!=NULL){
            struct Node * temp = current;
            current = current->next;
            free(temp);
        }
        table[i]=NULL;
    }
}
void printTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("table[%d] : ", i);

        struct Node *current = table[i];

        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }

        printf("NULL\n");
    }
}
void printSearchResult(int key) {
    struct Node *result = Search(key);

    if (result != NULL) {
        printf("Key %d : FOUND\n", key);
    }
    else {
        printf("Key %d : NOT FOUND\n", key);
    }
}
int main(){
    insert(12);
    insert(24);
    insert(36);
    insert(48);
    insert(34);
    insert(44);
    insert(54);
    printTable();
    printSearchResult(48);
    printSearchResult(67);
    delete(54);
    printTable();
    delete(34);
    printTable();
    delete(39);
    printTable();
    freetable();
    printTable();
}
