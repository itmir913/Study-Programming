#include <stdio.h>

int main(int argc, char **argv) {
    int a[10][10] = {};

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    int x = 2 - 1, y = 2 - 1;

    while (1) {
        if (a[x][y] == 2) {
            a[x][y] = 9;
            break;
        }

        a[x][y] = 9;

        if (a[x][y + 1] != 1) {
            y++;
        } else if (a[x + 1][y] != 1) {
            x++;
        } else {
            break;
        }
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}

