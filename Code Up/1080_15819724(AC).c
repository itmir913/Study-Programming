#include <stdio.h>

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);

    int i = 1, sum = 0;
    while (sum <= n) {
        sum += i;
        if (sum < n) {
            i++;
        }
    }

    printf("%d", i);

    return 0;
}

