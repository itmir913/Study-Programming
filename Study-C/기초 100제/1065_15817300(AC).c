#include <stdio.h>

int main(int argc, char **argv) {
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);

    if (n % 2 == 0) {
        printf("%d\n", n);
    }

    if (m % 2 == 0) {
        printf("%d\n", m);
    }

    if (l % 2 == 0) {
        printf("%d\n", l);
    }

    return 0;
}

