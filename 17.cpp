//Sharan.B(192210486//
#include <stdio.h>

void findMaxMin(int arr[], int low, int high, int *max, int *min) {
    if (low == high) {
        *max = *min = arr[low];
    } else if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
    } else {
        int mid = (low + high) / 2;
        int max1, min1, max2, min2;
        findMaxMin(arr, low, mid, &max1, &min1);
        findMaxMin(arr, mid + 1, high, &max2, &min2);
        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 < min2) ? min1 : min2;
    }
}

int main() {
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int max, min;
    findMaxMin(arr, 0, arr_size - 1, &max, &min);
    printf("Maximum element is %d\n", max);
    printf("Minimum element is %d\n", min);
    return 0;
}
