#include <stdio.h>

struct address{
    char name[20];
    char phone[20];
    char addr[30];
};

int main(){
    struct address list[5] = {
        {"kim", "111-1111","Busan"},
        {"Lee", "222-2222", "Seoul"},
        {"Park","333-3333", "Incheon"},
        {"Choi", "444-4444", "Daegu"},
        {"Kang", "555-5555","Gwangju"}
    };
    int i;
    for (i=0;i<5;i++){
        printf("%5s %10s % 10s\n", list[i].name,list[i].phone,list[i].addr);
    }
    return 0;
}