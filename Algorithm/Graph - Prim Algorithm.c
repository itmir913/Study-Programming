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
            graph->matrix[i][j] = 0;
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
            printf("%d\t", graph->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void freeGraph(graphType *graph) {
    free(graph->matrix[0]);
    free(graph->matrix);
}

// 프림 알고리즘 구현
void prim(graphType *graph, int startVertex) {
    int vertex_number = graph->vertex;
    if (startVertex >= vertex_number)
        return;

    printf("Prim algorithm starts with %c vertex.\n", vertexName[startVertex]);

    int *added_vertex = (int *) malloc(sizeof(int) * vertex_number); // 알고리즘에 포함된 정점을 TRUE로 표시하기 위한 배열
    for (int i = 0; i < vertex_number; i++) {
        added_vertex[i] = FALSE;
    }
    added_vertex[startVertex] = TRUE;

    int node_number = 0;
    while (node_number != (vertex_number - 1)) { // 간선이 n-1개가 될 때까지 반복
        int a = 0, b = 0, min = INT_MAX;

        for (int i = 0; i < vertex_number; i++) {
            if (added_vertex[i] == TRUE) { // 연결된 노드 중에서
                int *edge = graph->matrix[i];
                for (int j = 0; j < vertex_number; j++) {
                    if (i != j && // 자기 자신이 아니고
                        edge[j] != 0 && // 가중치가 0이 아니며
                        edge[j] < min && // 최솟값이고
                        added_vertex[j] == FALSE) { // 사이클을 형성하지 않으면
                        a = i, b = j, min = edge[j];
                    }
                }
            }
        }

        if (a != b) {
            printf("Vertex %c, %c is connected.\n", vertexName[a], vertexName[b]);
            added_vertex[a] = TRUE;
            added_vertex[b] = TRUE;
            node_number++;
        }
    }
}


int main(void) {
    int vertex_number = 10;
    graphType *graph = createGraph(vertex_number);

    insertEdge(graph, A, B, 3, FALSE);
    insertEdge(graph, A, D, 6, FALSE);
    insertEdge(graph, B, D, 5, FALSE);
    insertEdge(graph, B, G, 12, FALSE);
    insertEdge(graph, A, C, 17, FALSE);
    insertEdge(graph, C, E, 10, FALSE);
    insertEdge(graph, D, E, 9, FALSE);
    insertEdge(graph, E, G, 2, FALSE);
    insertEdge(graph, C, F, 8, FALSE);
    insertEdge(graph, E, F, 4, FALSE);
    insertEdge(graph, F, G, 14, FALSE);
    insertEdge(graph, B, H, 6, FALSE);
    insertEdge(graph, B, I, 7, FALSE);
    insertEdge(graph, H, I, 11, FALSE);
    insertEdge(graph, F, J, 15, FALSE);
    insertEdge(graph, E, J, 17, FALSE);
    insertEdge(graph, F, G, 14, FALSE);
    insertEdge(graph, G, H, 13, FALSE);

    printf("**** 인접 행렬 ****\n");
    showGraphMatrix(graph);

    printf("**** Prim 알고리즘 ****\n");
    prim(graph, A);

    freeGraph(graph);

    return 0;
}