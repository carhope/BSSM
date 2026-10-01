#include <stdio.h>
struct Student{
    int id;
    char name[20];
    int score;
};
void findStudent(struct Student p[], int ID){
    for (int i=0;i<5;i++){
        if (p[i].id == ID){
            printf("Student ID : %d",p[i].id);
            printf("%s",p[i].name);
            printf("Scores : %d",p[i].score);
        }
        else{
            print("Student not found");
        }
    }
}
int main(){
    
}