#include <stdio.h>

int main(int argc, char **argv) {

    char n[2001];
    fgets(n, 2000, stdin);
//    scanf("%s", &n);
    printf("%s", n);

    return 0;
}

