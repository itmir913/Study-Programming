#include <stdio.h>

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);

    int a[19][19] = {};
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x - 1][y - 1] = 1;
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

