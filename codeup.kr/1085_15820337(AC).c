#include <stdio.h>

int main(int argc, char **argv) {
    long long int h, b, c, s;
    scanf("%lld %lld %lld %lld", &h, &b, &c, &s);

    printf("%.1f MB", (float) (h * b * c * s) / (1024 * 1024 * 8));

    return 0;
}

