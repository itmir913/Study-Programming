#include <stdio.h>

int main(int argc, char **argv) {

    int n, m, l;
    scanf("%d.%d.%d", &n, &m, &l);
    printf("%04d.%02d.%02d", n, m, l);

    return 0;
}

