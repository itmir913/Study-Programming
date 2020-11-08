#include <stdio.h>

int main(int argc, char **argv) {
    int n;

    lable:
    scanf("%d", &n);
    if (n != 0) {
        printf("%d\n", n);
        goto lable;
    }

    return 0;
}

