#include <stdio.h>
#include <stdbool.h>

void swap(int *arr, int x, int y) {
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void quick_sort_unit(int *array, int lower, int upper) {
    if (upper <= lower) {
        return;
    }

    int pivot = array[lower];
    int start = lower;
    int stop = upper;

    while (lower < upper) {
        while (array[lower] <= pivot) {
            lower++;
        }
        while (array[upper] > pivot) {
            upper--;
        }
        if (lower < upper) {
            swap(array, upper, lower);
        }
    }

    swap(array, upper, start);
    quick_sort_unit(array, start, upper - 1);
    quick_sort_unit(array, upper + 1, stop);
}

void quick_sort(int *array, int size) {
    quick_sort_unit(array, 0, size - 1);
}


bool binary_search(const int *array, int size, int value) {
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (array[mid] == value) {
            return true;
        } else if (array[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);

    int array[n];
    for (int i = 0; i < n; i++) {
        scanf(" %d", &array[i]);
    }

    quick_sort(array, n);

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int search;
        scanf(" %d", &search);
        if (binary_search(array, n, search)) {
            printf("1 ");
        } else {
            printf("0 ");
        }
    }

    return 0;
}
