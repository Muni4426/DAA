//Sharan.B(192210486//
#include <stdio.h>
#define R 3
#define C 3

int min(int x, int y, int z) {
    if (x < y)
        return (x < z) ? x : z;
    else
        return (y < z) ? y : z;
}

int minCost(int cost[R][C]) {
    int dp[R][C];
    dp[0][0] = cost[0][0];
    for (int i = 1; i < R; i++)
        dp[i][0] = dp[i-1][0] + cost[i][0];
    for (int j = 1; j < C; j++)
        dp[0][j] = dp[0][j-1] + cost[0][j];
    for (int i = 1; i < R; i++)
        for (int j = 1; j < C; j++)
            dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + cost[i][j];
    return dp[R-1][C-1];
}

int main() {
    int cost[R][C] = {{1, 2, 3},
                      {4, 8, 2},
                      {1, 5, 3}};
    printf("Minimum cost to reach (2,2) = %d", minCost(cost));
    return 0;
}
