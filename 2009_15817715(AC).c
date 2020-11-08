#include <stdio.h>

int main(int argc, char **argv) {
    int k, n;
    scanf("%d %d", &k, &n);

    int num = 0;
    while (k >= n) {
        k -= n;
        num++;
        k++;
    }

    printf("%d", num);

    return 0;
}

