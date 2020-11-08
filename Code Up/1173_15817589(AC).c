#include <stdio.h>

int main(int argc, char **argv) {
    int h, m;
    scanf("%d %d", &h, &m);

    m -= 30;
    if (m < 0) {
        h--;
        m += 60;
    }

    if (h < 0) {
        h += 24;
    }

    printf("%d %d", h, m);

    return 0;
}

