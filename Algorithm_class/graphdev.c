#include <stdio.h>
#define V 5
int graph[V][V] = {
    {0,1,1,0,1},
    {1,0,0,1,0},
    {1,0,0,1,1},
    {0,1,1,0,0},
    {1,0,1,0,0}
};
int visited[V];

void initVisited(void){
    for (int i=0;i<V;i++){
        visited[i] = 0;
    }
}
void dfs(int v){
    visited[v]=1;
    printf("%d ",v);

    for (int i=0;i<V;i++){
        if(graph[v][i]&&!visited[i]){
            dfs(i);
        }
    }
}
void bfs(int start){
    int queue[V];
    int front = 0;
    int rear = 0;
    visited[start] = 1;
    queue[rear++]=start;
    while(front<rear){

    }
}
void printGraph(){
    printf("  ");
    for (int i=0;i<V;i++){
        printf("%d ",i);
    }
    printf("\n");
    for(int i=0;i<V;i++){
        printf("%d ",i);
        for(int j=0;j<V;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
}
int main(){
    printf("인접 행렬\n");
    printGraph();
    initVisited();
    dfs(0);
}