#include <stdio.h>

int main(int argc, char **argv) {
    long long int n;
    scanf("%lld", &n);

    if (n > 0) {
        printf("plus\n");
    } else {
        printf("minus\n");
    }

    if (n % 2 == 0) {
        printf("even\n");
    } else {
        printf("odd\n");
    }

    return 0;
}

