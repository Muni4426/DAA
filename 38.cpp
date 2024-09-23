//Sharan.B(192210486//
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4

int costMatrix[N][N] = {
    {9, 2, 7, 8},
    {6, 4, 3, 7},
    {5, 8, 1, 8},
    {7, 6, 9, 4}
};

int minCost = INT_MAX;
int finalAssignment[N];

void updateAssignment(int currentAssignment[]) {
    for (int i = 0; i < N; i++)
        finalAssignment[i] = currentAssignment[i];
}

int calculateCost(int assignment[]) {
    int cost = 0;
    for (int i = 0; i < N; i++)
        cost += costMatrix[i][assignment[i]];
    return cost;
}

void branchAndBound(int depth, int currentCost, int assignment[], bool used[]) {
    if (depth == N) {
        if (currentCost < minCost) {
            minCost = currentCost;
            updateAssignment(assignment);
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            assignment[depth] = i;
            used[i] = true;
            int newCost = currentCost + costMatrix[depth][i];
            
            if (newCost < minCost)
                branchAndBound(depth + 1, newCost, assignment, used);
            
            used[i] = false;
        }
    }
}

int main() {
    int assignment[N];
    bool used[N] = {false};

    branchAndBound(0, 0, assignment, used);

    printf("Optimal Assignment:\n");
    for (int i = 0; i < N; i++)
        printf("Worker %d -> Job %d\n", i, finalAssignment[i]);
    printf("Minimum Cost: %d\n", minCost);

    return 0;
}

