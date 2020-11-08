#include <stdio.h>

int main(int argc, char **argv) {
    int a[19][19] = {};
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; ++j) {
            int t;
            scanf("%d", &t);
            a[i][j] = t;
        }
    }

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        for (int j = 0; j < 19; ++j) {
            a[x-1][j] = !a[x-1][j];
        }

        for (int k = 0; k < 19; ++k) {
            a[k][y-1] = !a[k][y-1];
        }

    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

