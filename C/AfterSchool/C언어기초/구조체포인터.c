#include <stdio.h>

typedef struct Character {
    char name[20];
    int hp;
}C;

int main(){
    C player = {"K",100};
    C *p = &player;

    printf("%d\n",(*p).hp);
    printf("%s\n",p->name);
}