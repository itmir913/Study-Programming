#include <stdio.h>

int main(int argc, char **argv) {
    long long int n, m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", n & m);

    return 0;
}

