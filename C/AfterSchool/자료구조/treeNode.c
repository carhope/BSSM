#include <stdio.h>

typedef struct Node{
    char data;
    struct Node * left;
    struct Node * right;
}Node;

void preorder(Node * node){
    if (node == NULL){
        return;
    }
    printf("%c ",node->data);
    preorder(node->left);
    preorder(node->right);
}
void inorder(Node * node){
    if (node == NULL){
        return;
    }
    inorder(node->left);
    printf("%c ",node->data);
    inorder(node->right);
}
void postorder(Node * node){
    if (node == NULL){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%c ",node->data);
}
int countNodes(Node *node){
    if (node == NULL){
        return 0;
    }
    int le = countNodes(node->left);
    int ri = countNodes(node->right);
    return 1 + le + ri;
}
int main(){
    Node d = {'D',NULL,NULL};
    Node e = {'E',NULL,NULL};
    Node f = {'F',NULL,NULL};
    Node g = {'G',NULL,NULL};

    Node b = {'B',&d,&e};
    Node c = {'C',&f,&g};

    Node a = {'A',&b,&c};

    Node *root = &a;

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root); 
    printf("\n");

    printf("전체 노드수 : %d\n",countNodes(root));
}