#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);

    int count = 0;
    for (int i = 1; i <= (int) a / 2; ++i) {
        if (a % i == 0)
            count++;
    }

    printf("%d ", count);

    return 0;
}
