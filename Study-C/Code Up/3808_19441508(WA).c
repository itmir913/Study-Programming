#include <stdio.h>
#include <stdlib.h>

#define MEMOIZATION 2000000

unsigned long long derangement(int n, unsigned long long *arr) { // n>= 2
    if (n == 0 || n == 1) {
        return arr[n]; // D0 = 1, D1 = 0
    } else {
        unsigned long long n_minus_1, n_minus_2;

        if (arr[n - 2] == 0)
            arr[n - 2] = derangement(n - 2, arr);

        if (arr[n - 1] == 0)
            arr[n - 1] = derangement(n - 1, arr);

        n_minus_1 = arr[n - 1] % 1000000007;
        n_minus_2 = arr[n - 2] % 1000000007;

        arr[n] = (n - 1) * (n_minus_1 + n_minus_2) % 1000000007;

        return arr[n];
    }
}

int main(void) {
    int num;
    scanf("%d", &num);

    unsigned long long *arr = (unsigned long long *) malloc(sizeof(unsigned long long) * MEMOIZATION);

    arr[0] = 1;
    arr[1] = 0;
    for (int i = 2; i < MEMOIZATION; i++) {
        *(arr + i) = 0;
    }

    printf("%llu", derangement(num, arr));

    return 0;
}
