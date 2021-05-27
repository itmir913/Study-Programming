#include <stdio.h>

int main(int argc, char **argv) {
    int a, d, n;
    scanf("%d %d %d", &a, &d, &n);

    for (int i = 1; i < n; i++) {
        a += d;
    }

    printf("%d\n", a);

    return 0;
}

