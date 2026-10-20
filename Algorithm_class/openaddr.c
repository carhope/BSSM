#include <stdio.h>
#define TABLE_SIZE 7
#define EMPTY -1
#define DELETED -2
int table[TABLE_SIZE];


int hash(int key){
    return key% TABLE_SIZE;
}

int search(int key){
    int index = hash(key);
    int count = 0;
    while (count < TABLE_SIZE){
        if (table[index]==key){
            return index;
        }
        if (table[index]==EMPTY){
            return -1;
        }
        index=(index+1)%TABLE_SIZE;
        count++;
    }
    return EMPTY;
}
void insert(key){
    int count = 0;
    int index = hash(key);
    while(count<TABLE_SIZE){
        if(table[index]==EMPTY || table[index]==DELETED){
            table[index]=key;
            return;
        }
        index = (index+1)%TABLE_SIZE;
        count++;
    }
    printf("TABLE is FULL");
}
void delete(int key){
    int index = hash(key);
    int count = 0;
    while(count<TABLE_SIZE){
        if (table[index]==key){
            table[index] = DELETED;
        }
        if(table[index]==EMPTY){
            return;
        }
        index = (index+1)%TABLE_SIZE;
        count++;
    }
}
int main(){
    for (int i=0;i<TABLE_SIZE;i++){
        table[i]=EMPTY;
    }
}