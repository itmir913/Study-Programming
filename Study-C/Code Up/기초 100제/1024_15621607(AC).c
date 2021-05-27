#include <stdio.h>

int main(int argc, char **argv) {
    char a[30];
    scanf("%s", a);

    int i;
    for (i = 0; a[i] != '\0'; i++) {
        printf("\'%c\'\n", a[i]);
    }

    return 0;
}

