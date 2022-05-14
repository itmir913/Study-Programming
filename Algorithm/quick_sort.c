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