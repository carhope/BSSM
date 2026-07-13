#include <stdio.h>
int main(){
    char ch;
    printf("영어 소문자 입력하세요 : ");
    scanf("%c", &ch);
    switch (ch){
        case 'a' : printf("모음"); break;
        case 'e' : printf("모음"); break;
        case 'i' : printf("모음"); break;
        case 'o' : printf("모음"); break; 
        case 'u' : printf("모음"); break;
        default : printf("자음"); break;
    }
}
#include <stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	switch(a){
		case 89 : printf("A");

		case 79:printf("B");
		case 69:printf("C");
		case 59:printf("D");
        case 'd':printf("D");
		default : printf("E");

	}
}