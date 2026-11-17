#include <stdio.h>
#include <string.h>

#define V 13               // 장소(정점)의 개수: 0 ~ 12
#define INF 1000000000     // 직접 연결되지 않은 두 장소 사이의 거리
#define TITLE_SIZE 128

typedef struct {
    const char *title;  // 도서명
    int room;           // 도서가 있는 자료실 번호
} Book;

typedef struct {
    int from;
    int to;
    int minutes;
} Edge;

// 정점 번호와 실제 장소 이름
const char *places[V] = {
    "정문",           // 0
    "안내데스크",     // 1
    "중앙홀",         // 2
    "북측복도",       // 3
    "남측복도",       // 4
    "인문자료실",     // 5
    "과학자료실",     // 6
    "IT자료실",       // 7
    "문학자료실",     // 8
    "역사자료실",     // 9
    "디지털자료실",   // 10
    "보존자료실",     // 11
    "동측복도"        // 12
};

// 저장된 도서 목록: 도서명, 자료실 번호
const Book books[] = {
    {"철학의 위안", 5},
    {"사피엔스", 5},
    {"코스모스", 6},
    {"이기적 유전자", 6},
    {"자료구조", 7},
    {"C 프로그래밍", 7},
    {"클린 코드", 7},
    {"데미안", 8},
    {"어린 왕자", 8},
    {"총, 균, 쇠", 9},
    {"역사의 쓸모", 9},
    {"디지털 미디어", 10},
    {"고문헌 입문", 11}
};
#define BOOK_COUNT ((int)(sizeof(books) / sizeof(books[0])))

// 임의로 설계한 복잡한 무방향 그래프: 두 장소와 이동 시간(분)
const Edge edges[] = {
    {0, 1, 2}, {0, 2, 5},
    {1, 2, 2}, {1, 3, 4},
    {2, 3, 3}, {2, 4, 2}, {2, 12, 5},
    {3, 5, 3}, {3, 6, 4}, {3, 7, 7}, {3, 12, 3},
    {4, 8, 3}, {4, 9, 5}, {4, 10, 7}, {4, 12, 4},
    {5, 6, 2}, {5, 11, 8},
    {6, 7, 3}, {6, 12, 5},
    {7, 10, 6}, {7, 12, 4},
    {8, 9, 2}, {8, 10, 5},
    {9, 11, 4}, {9, 12, 6},
    {10, 11, 3}, {10, 12, 4},
    {11, 12, 7}
};
#define EDGE_COUNT ((int)(sizeof(edges) / sizeof(edges[0])))

// 인접 행렬 생성: 대각선 0, 미연결 INF, 무방향이므로 대칭
void initializeGraph(int graph[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < EDGE_COUNT; i++) {
        int a = edges[i].from;
        int b = edges[i].to;
        int time = edges[i].minutes;
        graph[a][b] = time;
        graph[b][a] = time;
    }
}

// 순차 탐색: 일치하는 도서의 자료실 번호, 없으면 -1 반환
int searchBook(const char *title) {
    for (int i = 0; i < BOOK_COUNT; i++) {
        if (strcmp(books[i].title, title) == 0) {
            return books[i].room;
        }
    }
    return -1;
}

// 다익스트라: 최단 거리 dist와 최단 경로 복원용 prev 계산
void dijkstra(int graph[V][V], int start, int dist[V], int prev[V]) {
    int visited[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        prev[i] = -1;
    }
    dist[start] = 0; // 사용자가 입력한 출발 정점의 거리만 0

    for (int step = 0; step < V; step++) {
        int current = -1;

        // 미방문 정점 중 거리가 가장 짧은 정점 선택
        // 동률이면 번호가 작은 정점을 선택
        for (int i = 0; i < V; i++) {
            if (!visited[i] &&
                (current == -1 || dist[i] < dist[current] ||
                 (dist[i] == dist[current] && i < current))) {
                current = i;
            }
        }

        if (current == -1 || dist[current] == INF) {
            break; // 남은 정점까지 갈 수 없음
        }

        visited[current] = 1;

        // 직접 연결된 미방문 정점의 거리를 갱신
        for (int next = 0; next < V; next++) {
            if (!visited[next] && graph[current][next] != INF) {
                int newDistance = dist[current] + graph[current][next];

                if (newDistance < dist[next]) { // 같은 거리면 기존 경로 유지
                    dist[next] = newDistance;
                    prev[next] = current;
                }
            }
        }
    }
}

// prev 배열을 목적지부터 따라간 뒤 역순으로 실제 경로 출력
void printPath(int destination, const int prev[V]) {
    int path[V];
    int count = 0;

    for (int v = destination; v != -1; v = prev[v]) {
        path[count++] = v;
    }

    for (int i = count - 1; i >= 0; i--) {
        int v = path[i];
        printf("[%d] %s", v, places[v]);
        if (i > 0) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main(void) {
    int graph[V][V];
    int dist[V], prev[V];
    int start;
    char title[TITLE_SIZE];

    initializeGraph(graph);

    printf("=== 도서관 도서 검색 및 최단 경로 안내 ===\n\n");
    printf("[장소 번호]\n");
    for (int i = 0; i < V; i++) {
        printf("%2d: %s\n", i, places[i]);
    }

    printf("\n[검색 가능한 도서]\n");
    for (int i = 0; i < BOOK_COUNT; i++) {
        printf("- %s\n", books[i].title);
    }

    printf("\n현재 위치 번호 (0~%d): ", V - 1);
    if (scanf("%d", &start) != 1 || start < 0 || start >= V) {
        printf("잘못된 위치 번호입니다.\n");
        return 1;
    }

    // scanf 후 입력 버퍼에 남은 개행 문자 제거
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }

    printf("검색할 도서명: ");
    if (fgets(title, sizeof(title), stdin) == NULL) {
        printf("도서명을 읽을 수 없습니다.\n");
        return 1;
    }
    title[strcspn(title, "\r\n")] = '\0';

    // 1. 순차 탐색으로 도서의 자료실 찾기
    int destination = searchBook(title);
    if (destination == -1) {
        printf("\n검색 결과: '%s' 도서를 찾지 못했습니다.\n", title);
        return 0;
    }

    // 2. 다익스트라로 모든 장소까지 최단 거리와 이전 정점 계산
    dijkstra(graph, start, dist, prev);

    // 3. 자료실, 시간, 실제 경로 출력
    printf("\n=== 검색 결과 ===\n");
    printf("도서명: %s\n", title);
    printf("도서 위치: [%d] %s\n", destination, places[destination]);

    if (dist[destination] == INF) {
        printf("최소 이동 시간: 계산 불가\n");
        printf("이동 경로 없음\n");
    } else {
        printf("최소 이동 시간: %d분\n", dist[destination]);
        printf("실제 이동 경로: ");
        printPath(destination, prev);
    }

    return 0;
}
