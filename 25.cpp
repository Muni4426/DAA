//Sharan.B(192210486//
#include <stdio.h>
#include <limits.h>

#define N 4
#define MAX_MASK (1 << N)

int min(int a, int b) { return (a < b) ? a : b; }

int tsp(int graph[N][N]) {
    int dp[MAX_MASK][N];
    for (int i = 0; i < MAX_MASK; i++)
        for (int j = 0; j < N; j++)
            dp[i][j] = INT_MAX;
    dp[1][0] = 0;
    for (int mask = 1; mask < MAX_MASK; mask++) {
        for (int u = 0; u < N; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < N; v++) {
                if (mask & (1 << v)) continue;
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], 
                                             dp[mask][u] + graph[u][v]);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i < N; i++)
        ans = min(ans, dp[MAX_MASK - 1][i] + graph[i][0]);
    return ans;
}

int main() {
    int graph[N][N] = {{0, 10, 15, 20},
                       {10, 0, 35, 25},
                       {15, 35, 0, 30},
                       {20, 25, 30, 0}};
    printf("The minimum cost of the TSP tour is: %d", tsp(graph));
    return 0;
}

