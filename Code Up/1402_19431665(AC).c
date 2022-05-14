#include <stdio.h>
#include <malloc.h>

int main() {
    int num;
    scanf("%d", &num);
    int *array = (int *) malloc(sizeof(int) * num);

    for (int i = 0; i < num; i++) {
        scanf("%d", &array[i]);
    }

    for (int i = num - 1; i >= 0; i--) {
        printf("%d ", array[i]);
    }

    return 0;
}

