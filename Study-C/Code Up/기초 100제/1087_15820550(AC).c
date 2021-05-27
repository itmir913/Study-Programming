#include <stdio.h>

int main(int argc, char **argv) {
    long long int n, sum = 0;
    scanf("%lld", &n);

    for (int i = 0; sum < n; i++) {
        sum += i;
    }

    printf("%lld\n", sum);

    return 0;
}

