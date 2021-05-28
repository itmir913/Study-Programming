#include <stdio.h>

int main() {
    int num;
    scanf("%d", &num);

    printf("%d %d", num / 60, (int) num % 60);
    return 0;
}

