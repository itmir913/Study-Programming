#include <stdio.h>

int main(int argc, char **argv) {
    int n, m;
    scanf("%d", &n);

    lable:
    scanf("%d", &m);
    printf("%d\n", m);

    if (--n != 0) {
        goto lable;
    }

    return 0;
}

