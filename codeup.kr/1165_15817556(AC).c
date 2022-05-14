#include <stdio.h>

int main(int argc, char **argv) {
    int a, b;
    scanf("%d %d", &a, &b);

    while(a < 90){
        b++;
        a+=5;
    }

    printf("%d", b);

    return 0;
}

