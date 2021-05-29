#include <stdio.h>

int main(void) {
    char input[10];
    scanf("%s", input);

    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        sum += *(input + i) - 48;
    }

    if (sum % 7 == 4) printf("suspect");
    else printf("citizen");

    return 0;
}
