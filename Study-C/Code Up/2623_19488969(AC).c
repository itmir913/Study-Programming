#include <stdio.h>

int gcd(int a, int b) { // GCD 알고리즘
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    int n;
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }

    return a;
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d", gcd(a, b));

    return 0;
}

