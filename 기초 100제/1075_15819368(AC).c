#include <stdio.h>

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);

    while (n > 0) {
        n -= 1;
        printf("%d\n", n);
    }

    return 0;
}

