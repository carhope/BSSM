#include <stdio.h>
struct Character
{
    char name[20];
    int level;
    int hp;
};

int main(){
    struct Character s1 ={"Kim",5,100};
    struct Character *p;
    p = &s1;
    p->level+=1;
    p->hp+=20;
    printf("%s : %d ,%d",s1.name,s1.level,s1.hp);
    return 0;
}
