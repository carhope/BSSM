#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node * left;
    struct Node * right;
}Node;

Node * createNode(int data){
    Node * newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node * insert(struct Node * curNode, int insertdata){
    if(curNode==NULL){
        return createNode(insertdata);
    }
    else if (curNode->data < insertdata){
        curNode->left = insert(curNode->left,insertdata);
    }
    else if (curNode->data > insertdata){
        curNode->right = insert(curNode->right,insertdata);
    }
    return curNode;
}
struct Node * search(struct Node * curNode, int target){
    while (curNode!= NULL){
        if (curNode->data == target){
            return curNode;
        }
        else if(curNode->data < target){
            curNode = curNode->left;
        }
        else if (curNode->data > target){
            curNode = curNode->right;
        }
    }
    return NULL;
}
    int values[100];
    int count;
    struct Node * root;

int main(){


    scanf("%d",&count);
    for (int i=0;i<count;i++){
        scanf("%d",&values[i]);
        root = insert(root,values[i]);
    }
    int target = 55;
    if(search(root,55)==NULL){
        printf("%d NOT FOUND",target);
    }
    else{
        printf("%d FOUND",target);
    }
}