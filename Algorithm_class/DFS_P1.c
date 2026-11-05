#include <stdio.h>


int n,m,s,t;
int arr[100][100];
int visited[100];
int DFS(int s, int t){
    if(s==t){
        return 1;
    }
    
    visited[s] = 1;
    for (int i=0;i<n;i++){
        if(arr[s][i]&&!visited[i]){
            if(DFS(i,t)){
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d %d",&n, &m);
    for (int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        arr[a][b] = 1;
    }
    scanf("%d %d",&s,&t);
    
    if(DFS(s,t)){
        printf("YES");
    }
    else{
        printf("NO");
    }
}