#include <stdio.h>

int main(int argc, char **argv) {
    int n, m = 0xF;
    scanf("%x", &n);

    for (int i = 1; i <= m; i++) {
        printf("%X*%X=%X\n", n, i, n * i);
    }

    return 0;
}

