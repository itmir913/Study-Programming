#include <stdio.h>

int main(int argc, char **argv) {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d", n > m ? n : m);

    return 0;
}

