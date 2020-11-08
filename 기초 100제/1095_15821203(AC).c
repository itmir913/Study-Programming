#include <stdio.h>

int main(int argc, char **argv) {
    int n, t, min = -1;
    scanf("%d", &n);

    int a[10000] = {};
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        a[i] = t;
        if ((min == -1) || (t < min)) {
            min = t;
        }
    }

    printf("%d ", min);

    return 0;
}

