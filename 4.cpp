//Sharan.B(192210486//
#include <stdio.h>

int findLargest(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main() {
    int arr[] = {10, 5, 7, 15, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Largest element: %d\n", findLargest(arr, n));
    return 0;
}

