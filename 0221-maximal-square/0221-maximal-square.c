int min(int a, int b)
{
    return (a < b) ? a : b;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize)
{
    if(matrixSize == 0)
        return 0;

    int rows = matrixSize;
    int cols = matrixColSize[0];

    int dp[301][301] = {0};

    int maxSide = 0;

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= cols; j++)
        {
            if(matrix[i-1][j-1] == '1')
            {
                dp[i][j] = 1 + min(dp[i-1][j],
                              min(dp[i][j-1], dp[i-1][j-1]));

                if(dp[i][j] > maxSide)
                    maxSide = dp[i][j];
            }
        }
    }

    return maxSide * maxSide;
}