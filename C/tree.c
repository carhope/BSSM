#include <stdio.h>
#include <stdlib.h> //malloc 함수 사용
#include <memory.h> //memory 함수 사용

typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;


}TreeNode;

int main(){
    
    TreeNode *A, *B, *C,*D,*E;
    A = (TreeNode*)malloc(sizeof(TreeNode));
    B = (TreeNode*)malloc(sizeof(TreeNode));
    C = (TreeNode*)malloc(sizeof(TreeNode));
    D = (TreeNode*)malloc(sizeof(TreeNode));
    E = (TreeNode*)malloc(sizeof(TreeNode));
    A->data = 10;
    A->left = B;
    A->right = C;

    B->data =20;
    B->left =D;
    B->right =NULL;

    C->data =15;
    C->left =E;
    C->right =NULL;

    D->data =40;
    D->left =NULL;
    D->right=NULL;

    E->data=35;
    E->left=NULL;
    E->right=NULL;
int k;
    scanf("%d",&k);

    printf("기본검 :%d\n",A->data);
    printf("불의 검 : %d\n",A->left->data);
    printf("태양의 검 :%d\n",A->left->left->data);
    printf("태양의 검 최종루트 공격력합계 :%d",A->data+A->left->data+A->left->left->data+k);


}