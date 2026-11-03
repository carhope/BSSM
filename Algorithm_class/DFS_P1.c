#include <stdio.h>


int n,m,s,t;
int arr[100][100];
int visited[100];
void DFS(int s, int t){
    
    visited[s] = 1;
    for (int i=0;i<n;i++){
        if(s==t){
            printf("YES");
            return;
        }
        if(arr[s][i]&&!visited[i]){
            DFS(i,t);
        }
    }
    printf("NO");
}
int main(){
    scanf("%d %d",&n, &m);
    for (int i=0;i<m;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    scanf("%d %d",&s,&t);
    for (int i=0;i<m;i++){
        visited[i] = 0;
    }
    DFS(s,t);
}