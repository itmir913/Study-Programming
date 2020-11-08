#include <stdio.h>

int main(int argc, char **argv) {
    long long int a, m, d, n;
    scanf("%lld %lld %lld %lld", &a, &m, &d, &n);

    for (int i = 1; i < n; i++) {
        a = (a * m) + d;
    }

    printf("%lld\n", a);

    return 0;
}

