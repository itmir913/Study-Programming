#include <stdio.h>

int main(int argc, char **argv) {
    long long int a, r, n;
    scanf("%lld %lld %lld", &a, &r, &n);

    for (int i = 1; i < n; i++) {
        a *= r;
    }

    printf("%lld\n", a);

    return 0;
}

