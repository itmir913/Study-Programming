#include <stdio.h>

int main(int argc, char **argv) {
    int n, t;
    scanf("%d", &n);

    int a[10000] = {};
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        a[i] = t;
    }

    for (int i = n - 1; i >= 0; --i) {
        printf("%d ", a[i]);
    }

    return 0;
}

