#include <stdio.h>

int main(int argc, char **argv) {
    int n = 1;

    while (n != 0) {
        scanf("%d", &n);
        if (n != 0) {
            printf("%d\n", n);
        }
    }

    return 0;
}

