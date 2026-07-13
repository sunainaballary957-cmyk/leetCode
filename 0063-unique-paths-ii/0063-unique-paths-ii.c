#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    int rows = obstacleGridSize;
    int cols = obstacleGridColSize[0];

    int dp[101][101] = {0};

    // If starting cell has obstacle
    if(obstacleGrid[0][0] == 1)
        return 0;

    dp[0][0] = 1;

    // First column
    for(int i = 1; i < rows; i++)
    {
        if(obstacleGrid[i][0] == 0)
            dp[i][0] = dp[i - 1][0];
    }

    // First row
    for(int j = 1; j < cols; j++)
    {
        if(obstacleGrid[0][j] == 0)
            dp[0][j] = dp[0][j - 1];
    }

    // Fill remaining cells
    for(int i = 1; i < rows; i++)
    {
        for(int j = 1; j < cols; j++)
        {
            if(obstacleGrid[i][j] == 0)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[rows - 1][cols - 1];
}