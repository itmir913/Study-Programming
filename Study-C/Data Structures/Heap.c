#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MAX_HEAP_SIZE = 30;
int size = 0; // 히프에 들어있는 원소 개수

void *createHeap(int heap_size) {
    return malloc(sizeof(int) * heap_size);
}

int isEmptyHeap(void) {
    return size == 0;
}

int isFullHeap(void) {
    return size == MAX_HEAP_SIZE;
}

void insertHeap(int *heap, int item) {
    if (!isFullHeap()) {
        size++;
        heap[size] = item; // 히프의 맨 마지막 노드에 원소 삽입

        int index = size;
        int parent = index / 2;
        while ((index > 0) && (heap[index] > heap[parent])) {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;

            index = parent;
            parent = index / 2;
        }
    } else {
        MAX_HEAP_SIZE *= 2;
        realloc(heap, sizeof(int) * MAX_HEAP_SIZE);
        insertHeap(heap, item);
    }
}

int popHeap(int *heap) {
    int result = heap[1]; // 루트 원소 값 저장

    int index = 1;
    heap[index] = heap[size]; // 가장 마지막에 있는 원소를 루트 원소로 저장
    heap[size] = -1; // 맨 마지막 원소 값 초기화해줘야 비교 연산할 때 오류가 생기지 않음
    size--;

    while (index < size) {
        int child = index * 2;
        if (heap[child] < heap[child + 1])
            child++; // 왼쪽, 오른쪽 자식 중에서 큰 자식 선택

        if (heap[index] > heap[child]) { // 자식보다 크면 중단
            break;
        } else {
            int temp = heap[child];
            heap[child] = heap[index];
            heap[index] = temp;

            index = child;
        }
    }

    return result;
}

void printHeap(int *heap) {
    int blank_i = 1, sum = 0;

    for (int i = 1; i <= size; i++) {
        // heap[0]부터 시작 X, heap[1]부터 시작
        // 이유: insertHeap()에서 부모 Heap 인덱스 계산의 편의를 위해서
        printf("%d\t", heap[i]);

        sum++;
        if (pow(2, blank_i - 1) == sum) {
            printf("\n");
            blank_i++;
            sum = 0;
        }
    }

    printf("\n\n");
}

int main(void) {
    // 히프 생성
    int *heap = createHeap(MAX_HEAP_SIZE);

    // 히프 삽입
    insertHeap(heap, 20);
    insertHeap(heap, 15);
    insertHeap(heap, 19);
    insertHeap(heap, 8);
    insertHeap(heap, 13);
    insertHeap(heap, 10);
    insertHeap(heap, 17);
    insertHeap(heap, 40);
    insertHeap(heap, 30);
    insertHeap(heap, 23);
    insertHeap(heap, 78);

    // 현재 히프 출력
    printf("원소 삽입 연산 후 히프 구조\n");
    printHeap(heap);

    // 히프 삭제
    popHeap(heap);
    popHeap(heap);

    // 현재 히프 출력
    printf("원소 2개 삭제 연산 후 히프 구조\n");
    printHeap(heap);

    free(heap);

    return 0;
}