#include <stdio.h>

int main(int argc, char **argv) {
    int N;
    scanf("%d", &N);

    int max = 10000 + 1;
    int array[max];

    for (int i = 0; i < max; i++) {
        array[i] = 0;
    }

    for (int i = 0; i < N; i++) {
        int input;
        scanf("%d", &input);
        array[input] += 1;
    }

    for (int i = 0; i < max; i++) {
        if (array[i] > 0) {
            for (int j = 0; j < array[i]; j++) {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
