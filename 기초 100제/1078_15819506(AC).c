#include <stdio.h>

int main(int argc, char **argv) {

    int sum = 0;
    int n, i;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        if (i % 2 == 0)
            sum += i;
    }

    printf("%d\n", sum);

    return 0;
}

