#include <stdio.h>

int main(int argc, char **argv) {
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);
    printf("%s\n", n % 2 == 0 ? "even" : "odd");
    printf("%s\n", m % 2 == 0 ? "even" : "odd");
    printf("%s\n", l % 2 == 0 ? "even" : "odd");

    return 0;
}

