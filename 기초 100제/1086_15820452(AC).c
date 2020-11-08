#include <stdio.h>

int main(int argc, char **argv) {
    long long int w, h, b;
    scanf("%lld %lld %lld", &w, &h, &b);

    printf("%.2f MB", (float) (w * h * b) / (1024 * 1024 * 8));

    return 0;
}

