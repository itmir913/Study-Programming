#include <stdio.h>

int main(int argc, char **argv) {
    long long int a, b, c, i = 1;
    scanf("%lld %lld %lld", &a, &b, &c);

    while (1) {
        if ((i % a == 0) && (i % b == 0) && (i % c == 0)) {
            break;
        }
        i++;
    }

    printf("%lld\n", i);

    return 0;
}

