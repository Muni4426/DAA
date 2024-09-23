//Sharan.B(192210486//
#include <stdio.h>

void insertNumber(int arr[], int* n, int pos, int num) {
    for (int i = *n; i > pos; i--)
        arr[i] = arr[i-1];
    arr[pos] = num;
    (*n)++;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5, pos = 2, num = 10;
    printf("Before insertion: ");
    printArray(arr, n);
    insertNumber(arr, &n, pos, num);
    printf("After insertion: ");
    printArray(arr, n);
    return 0;
}
