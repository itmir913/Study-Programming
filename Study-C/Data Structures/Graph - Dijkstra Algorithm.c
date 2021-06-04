#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE  1
#define FALSE 0

char vertexName[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};
enum vertex_name {
    A, B, C, D, E, F, G, H, I, J, K
};

int **create2x2Matrix(int vertex) { // https://codeng.tistory.com/8
    int height = vertex, width = vertex;
    int **arr = (int **) malloc(sizeof(int *) * height);
    arr[0] = (int *) malloc(sizeof(int) * width * height);

    for (int i = 1; i < height; i++) {
        arr[i] = arr[i - 1] + width;
    }

    return arr;
}

typedef struct graphType {
    int vertex;
    int **matrix;
} graphType;

graphType *createGraph(int vertex_number) {
    graphType *graph = (graphType *) malloc(sizeof(graphType));

    graph->vertex = vertex_number;
    graph->matrix = create2x2Matrix(vertex_number);

    for (int i = 0; i < vertex_number; i++) {
        for (int j = 0; j < vertex_number; j++) {
            if (i == j)
                graph->matrix[i][j] = 0;
            else
                graph->matrix[i][j] = INT_MAX;
        }
    }

    return graph;
}

void insertEdge(graphType *graph, int a, int b, int weight, int isDirectedGraph) {
    if (a == b) // 정점 자신을 가리키는 간선은 제외한다
        return;

    int MAX = graph->vertex;
    if (a < MAX && b < MAX) {
        graph->matrix[a][b] = weight;

        if (!isDirectedGraph) // 무방향 그래프일 경우 행렬의 주대각선을 기준으로 대칭이어야 한다
            graph->matrix[b][a] = weight;
    }
}

void showGraphMatrix(graphType *graph) {
    for (int i = 0; i < graph->vertex; i++) {
        for (int j = 0; j < graph->vertex; j++) {
            int num = graph->matrix[i][j];
            if (num == INT_MAX) {
                printf("%c\t", '*');
            } else {
                printf("%d\t", num);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void freeGraph(graphType *graph) {
    free(graph->matrix[0]);
    free(graph->matrix);
}




// Dijkstra 알고리즘 구현

void printStep(const int *vertex, const int *distance, int vertex_number, int step) {
    printf("%3d단계 distance: [", step);
    for (int i = 0; i < vertex_number; i++)
        if (distance[i] == INT_MAX)
            printf("%4c", '*');
        else
            printf("%4d", distance[i]);
    printf("%4c", ']');

    printf(",\n  Vertex set: ");

    for (int i = 0; i < vertex_number; i++)
        if (vertex[i] == TRUE)
            printf("%3c", i + 65);

    printf("\n");
}

int nextVertex(const int *vertex, const int *distance, int vertex_number) { // 최소 거리를 갖는 정점 반환
    int min = INT_MAX, minPos = -1;
    for (int i = 0; i < vertex_number; i++) {
        if ((distance[i] < min) && !vertex[i]) {
            min = distance[i];
            minPos = i;
        }
    }
    return minPos;
}

void dijkstra(graphType *graph, int startVertex) {
    printf("Dijkstra algorithm starts with %c vertex.\n", vertexName[startVertex]);

    int vertex_number = graph->vertex;
    int *distance = (int *) malloc(sizeof(int) * vertex_number);
    int *vertex = (int *) malloc(sizeof(int) * vertex_number);

    for (int i = 0; i < vertex_number; i++) {
        distance[i] = graph->matrix[startVertex][i]; // 인접 행렬의 시작 정점 행을 distance로 설정
        vertex[i] = FALSE;
    }

    vertex[startVertex] = TRUE; // 시작 정점 추가
    distance[startVertex] = 0; // 시작 정점의 distance를 0으로 설정

    int next, step = 0;
    for (int i = 0; i < vertex_number; i++) {
        printStep(vertex, distance, vertex_number, step);

        next = nextVertex(vertex, distance, vertex_number);
        if (next == -1)
            continue;

        vertex[next] = TRUE; // 찾은 정점을 집합에 추가

        for (int w = 0; w < vertex_number; w++) {
            if (!vertex[w]) { // 집합에 포함되지 않은 정점 중에서
                int weight = graph->matrix[next][w];
                if (weight == INT_MAX)
                    continue;
//                    weight = 100000; // TODO weight가 INT_MAX일 경우, distance[next] + weight 연산에서 오버플로우 발생

                if (distance[next] + weight < distance[w]) // 새로 추가된 정점에 의해 단축되는 경로가 있을 경우
                    distance[w] = distance[next] + weight; // distance 값 수정
            }
        }

        step++;
    }
}

int main(void) {
    int vertex_number = 10;
    graphType *graph = createGraph(vertex_number);

    insertEdge(graph, A, B, 10, TRUE);
    insertEdge(graph, A, C, 5, TRUE);
    insertEdge(graph, B, C, 2, TRUE);
    insertEdge(graph, B, D, 1, TRUE);
    insertEdge(graph, C, B, 3, TRUE);
    insertEdge(graph, C, D, 9, TRUE);
    insertEdge(graph, C, E, 2, TRUE);
    insertEdge(graph, D, E, 4, TRUE);
    insertEdge(graph, E, A, 7, TRUE);
    insertEdge(graph, E, D, 6, TRUE);
    insertEdge(graph, D, F, 5, TRUE);
    insertEdge(graph, F, E, 8, TRUE);
    insertEdge(graph, F, G, 10, TRUE);
    insertEdge(graph, A, H, 8, TRUE);
    insertEdge(graph, H, C, 6, TRUE);
    insertEdge(graph, C, I, 4, TRUE);
    insertEdge(graph, E, J, 11, TRUE);
    insertEdge(graph, G, J, 9, TRUE);
    insertEdge(graph, I, J, 7, TRUE);
    insertEdge(graph, E, G, 8, TRUE);

    printf("**** 인접 행렬 ****\n");
    showGraphMatrix(graph);

    printf("**** Dijkstra 알고리즘 ****\n");
    dijkstra(graph, A);

    freeGraph(graph);

    return 0;
}