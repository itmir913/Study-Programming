#include <stdio.h>

int derangement(int n) { // n>= 2
    if (n == 0) return 1; // D0 = 1
    else if (n == 1) return 0; // D1 = 0
    return (n - 1) * (derangement(n - 1) + derangement(n - 2));
}

int main(void) {
    int num;
    scanf("%d", &num);

    printf("%d", derangement(num));

    return 0;
}
