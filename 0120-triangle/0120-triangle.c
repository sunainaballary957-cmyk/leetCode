#include <stdlib.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize)
{
    int *dp = (int *)malloc(triangleSize * sizeof(int));

    // Copy last row into dp
    for(int i = 0; i < triangleColSize[triangleSize - 1]; i++)
    {
        dp[i] = triangle[triangleSize - 1][i];
    }

    // Bottom to top
    for(int i = triangleSize - 2; i >= 0; i--)
    {
        for(int j = 0; j <= i; j++)
        {
            if(dp[j] < dp[j + 1])
                dp[j] = triangle[i][j] + dp[j];
            else
                dp[j] = triangle[i][j] + dp[j + 1];
        }
    }

    int answer = dp[0];
    free(dp);

    return answer;
}