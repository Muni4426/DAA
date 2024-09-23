//Sharan.B(192210486//
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void printSubset(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void subsetSum(int s[], int t[], int s_size, int t_size, int sum, int ite, int target_sum) {
    if (target_sum == sum) {
        printSubset(t, t_size);
        if (ite + 1 < s_size && sum - s[ite] + s[ite + 1] <= target_sum)
            subsetSum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        return;
    }
    else {
        if (ite < s_size && sum + s[ite] <= target_sum)
            subsetSum(s, t, s_size, t_size, sum + s[ite], ite + 1, target_sum);
        if (ite + 1 < s_size && sum + s[ite + 1] <= target_sum)
            subsetSum(s, t, s_size, t_size, sum, ite + 1, target_sum);
    }
}

void generateSubsets(int s[], int size, int target_sum) {
    int t[MAX] = {0};
    subsetSum(s, t, size, 0, 0, 0, target_sum);
}

int main() {
    int weights[] = {10, 7, 5, 18, 12, 20, 15};
    int size = sizeof(weights) / sizeof(weights[0]);
    generateSubsets(weights, size, 35);
    return 0;
}
