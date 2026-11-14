#include <stdio.h>
#define INF 999
#define N 6

int graph[N][N] = {
    {0, 4, 3, INF,INF,INF},
    {4, 0, INF, 6, INF, INF},
    {3, INF, 0, 7, 8, INF},
    {5, 6, 7, 0, 9, 2},
    {INF, INF, 8, 9,0, 1},
    {INF, INF, INF, 2, 1,0}

};
int dist[100] = {INF};
int visited[100];
int start = 0;

int findMinVertex(){
    int min = INF;
    int minIndex = -1;

    for (int i=0;i<N;i++){
        if(visited[i]==0 && dist[i]<min){
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printdi(){
    for (int i=0;i<N;i++){
        if(dist[i] == INF){
            printf("%c : INF\n",'A'+i);
        }
        else{
            printf("%c : %d\n",'A'+i,dist[i]);
        }
    }
}

void dijkstra(int start){
    
    for (int i = 0; i<N;i++){
        dist[i] = graph[start][i];
    }
    visited[start] = 1;
    for (int i=0;i<N;i++){
        int cur = findMinVertex();
        visited[cur] = 1;
        for (int j=0;j<N;j++){
            if(!visited[j]){
                if(dist[cur] + graph[cur][j] < dist[j]){
                    dist[j] = dist[cur] + graph[cur][j];
                }
            }
        }
    }

}

int main(){
    dijkstra(start);
    for(int i=0;i<N;i++){
        printf("%d\n",dist[i]);
    }
    printdi();
    return 0;
}