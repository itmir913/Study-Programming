#include <stdio.h>

int main(int argc, char **argv) {
    char n = '\0';

    while (n != 'q') {
        scanf("%c", &n);
        printf("%c", n);
        if (n == 'q') {
            break;
        }
    }

    return 0;
}

