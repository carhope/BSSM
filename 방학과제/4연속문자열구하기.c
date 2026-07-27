#include <stdio.h>
int main() {
	char input[100];
	scanf("%s",input);
	int seq=1;
	int go=0;
	while (input[go]!='\0'){
        if (input[go]==input[go+1] && input[go+1]!='\0'){
            seq++;
        }
        else{
            printf("%c%d",input[go],seq);
            seq=1;
        }
        go++;
	}
	return 0;
}

#include <stdio.h>
int main() {
	char input[100];
	scanf("%s",input);
	char cur;
	int seq=0;
	int go=1;
	cur = input[0];
	while (input[go]!='\0'){
		seq=1;
        printf("%c",cur);
		while (seq!=0){
			if (input[go]==cur){
			seq++;
      }
      else {
        printf("%d ",seq);
        seq=0;
			}
    }
	}
	return 0;
}

