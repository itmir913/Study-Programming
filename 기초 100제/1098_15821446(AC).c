#include <stdio.h>

int main(int argc, char **argv) {
    int h, w;
    scanf("%d %d", &h, &w);

    int a[100][100] = {};

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int l, d, x, y;
        scanf("%d %d %d %d", &l, &d, &x, &y);

        if (d == 0) {
            for (int j = 0; j < l; ++j) {
                a[x - 1][y - 1] = 1;
                y++;
            }
        } else if (d == 1) {
            for (int j = 0; j < l; ++j) {
                a[x - 1][y - 1] = 1;
                x++;
            }
        }
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

