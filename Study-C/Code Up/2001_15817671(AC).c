#include <stdio.h>

int main(int argc, char **argv) {
    int a, b, c, d, e;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);

    int pasta = (a < b ? a : b) < c ? (a < b ? a : b) : c;
    int ju = d < e ? d : e;

    printf("%.1f", (pasta + ju) * 1.1);

    return 0;
}

