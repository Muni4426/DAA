//Sharan.B(192210486//
#include <stdio.h>
#include <limits.h>

void minMaxSequence(int arr[], int n) {
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
        printf("Min: %d, Max: %d\n", min, max);
    }
}

int main() {
    int arr[] = {3, 2, 5, 1, 7, 8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    minMaxSequence(arr, n);
    return 0;
}
