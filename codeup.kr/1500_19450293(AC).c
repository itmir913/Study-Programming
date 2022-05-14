#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int height, int width) { // https://codeng.tistory.com/8
    int **arr;

    arr = (int **) malloc(sizeof(int *) * height);
    arr[0] = (int *) malloc(sizeof(int) * width * height);

    for (int i = 1; i < height; i++) {
        arr[i] = arr[i - 1] + width;
    }

    return arr;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int **aa = createMatrix(n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &aa[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", aa[i][j]);
        }
        printf("\n");
    }

    free(aa[0]);
    free(aa);

    return 0;
}

