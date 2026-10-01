#include <stdio.h>
#include <string.h>

struct info {
    int PID;
    char name[50];
    int price;
    int stock;
};

int main(){
    struct info one;
    printf("Product ID : ");
    scanf("%d",&one.PID);
    printf("Name : ");
    scanf("%s",one.name);
    printf("Price : ");
    scanf("%d",&one.price);
    printf("Stock : ");
    scanf("%d",&one.stock);

    printf("%d %s %d %d",one.PID,one.name,one.price,one.stock);
}