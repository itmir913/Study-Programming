#include <stdio.h>

int main(int argc, char **argv) {
    long long int n, m, l;
    scanf("%lld %lld %lld", &n, &m, &l);
    long long int sum = n + m + l;
    printf("%lld\n", sum);
    printf("%.1f\n", (float) sum / 3);

    return 0;
}

