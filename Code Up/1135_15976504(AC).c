#include <stdio.h>

int main(int argc, char **argv) {
    int a, b;
    scanf("%d %d", &a, &b);

    if (a >= b) {
        printf("1");
    } else {
        printf("0");
    }

    return 0;
}

