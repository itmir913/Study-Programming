#include <stdio.h>

int main(int argc, char **argv) {
    long long int n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", n + m);
    printf("%lld\n", n - m);
    printf("%lld\n", n * m);
    printf("%lld\n", (long long int) n / m);
    printf("%lld\n", (long long int) n % m);
    printf("%.2f\n", (float) n / m);

    return 0;
}

