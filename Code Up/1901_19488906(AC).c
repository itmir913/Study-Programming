#include <stdio.h>

void fact(int count, int n) {
    printf("%d\n", count);
    if (count < n)
        fact(count + 1, n);
}

int main(void) {
    int n;
    scanf("%d", &n);

    fact(1, n);

    return 0;
}

