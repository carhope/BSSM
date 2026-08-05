#include <stdio.h>
 // 하기전 생각 
/*우선 입력 정수를 저장할 변수 in, in의 개수를 출력할 변수 total,
구조는 in이 들어오면 
for int i=0;i<n;i++
포인터 배열 pNoArr 에 하나씩 차례대로 저장
하지만 이걸 내림차 순으로 정렬해야함
다시 for문 돌려서 
내림차순으로 버블정렬하고

in의 total을 설정할 배열 abc를 [1000][1000] = {0}으로 초기화
포인터 배열pNoArr에서 하나하나 꺼내면서 그 주소로 가서
0이던걸 1++함 그럴 려면 역참조 변수가 있어야함?
이제 반복문 다 돌았으면 pNoArr에 가서 하나하나 가면서 그 주소를 출력하고 주소 안에 있는 값을 출력하면
그 숫자와 몇번 나왔는지 출현개수를 알 수 있다.

하지만 내가 짠 로직에는 오류가 한가지 있다 오류이면서 치명적인 문제이다. 이차원 배열로 선언하는게 문제이다.
굳이 이차원 말고 1차원으로 하면되고 해야하는데 왜 2차원으로 생각한거지?
따라서 abc[1000]이면 충분하다 0으로 초기화 하고
그렇지만 내 로직보다 더 좋은 로직은
정렬하고 바로 그걸 연속 숫자로 보고 끊기면 출력하는 로직이다.*/
int main(){
    int abc[1000];
    int n;
    int total=1;
    int temp;
    scanf("%d",&n);
    //int pNoArr[1000];
    for (int i=0;i<n;i++){
        scanf("%d",&abc[i]);
    }
    for (int l=0;l<n-1;l++){
        for (int j=0;j<n-1;j++){
            if(abc[j]>abc[j+1]){
                temp=abc[j];
                abc[j] = abc[j+1];
                abc[j+1] = temp;
            }
        }
    }
    for (int j=0;j<n;j++){
        printf("%d ", abc[j]);
    }
    for (int k=0;k<n;k++){
        if (k==n-1 || abc[k]!=abc[k+1]){
            printf("%d %d\n",abc[k],total);
            total =1;
        }
        else{
            total++;
        }
    }
}