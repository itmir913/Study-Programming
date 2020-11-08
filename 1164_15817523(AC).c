#include <stdio.h>

int main(int argc, char **argv) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int aa = 1, bb = 1, cc = 1;
    if (a <= 170)
        aa = 0;

    if (b <= 170)
        bb = 0;

    if (c <= 170)
        cc = 0;

    if (aa && bb && cc)
        printf("PASS\n");
    else
        printf("CRASH\n");

    return 0;
}

