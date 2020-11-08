#include <stdio.h>

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);

    if (n >= 90) {
        printf("A\n");
    } else if (n >= 70) {
        printf("B\n");
    } else if (n >= 40) {
        printf("C\n");
    } else {
        printf("D\n");
    }

    return 0;
}

