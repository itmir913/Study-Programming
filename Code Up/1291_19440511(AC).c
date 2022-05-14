#include <stdio.h>

int main(void) {
    int a, b, c, min;
    scanf("%d %d %d", &a, &b, &c);

    if (a > b) min = b;
    else min = a;

    if (c < min) min = c;

    int vaccine = 1;
    for (int i = 1; i <= min; ++i) {
        if ((a % i == 0) && (b % i == 0) && (c % i == 0))
            vaccine = i;
    }

    printf("%d ", vaccine);

    return 0;
}
