#include <stdio.h>

int main(int argc, char **argv) {
    char n, m='a';
    scanf("%c", &n);

    do {
        printf("%c\n", m);
        m++;
    }while (m <= n);

    return 0;
}

