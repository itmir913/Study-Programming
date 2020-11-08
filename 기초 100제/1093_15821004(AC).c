#include <stdio.h>

int main(int argc, char **argv) {
    int n, t;
    scanf("%d", &n);

    int a[24] = {};
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        a[t-1] += 1;
    }

    for (int i = 0; i < 23; ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}

