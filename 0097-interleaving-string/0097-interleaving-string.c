#include <stdbool.h>
#include <string.h>

bool isInterleave(char *s1, char *s2, char *s3)
{
    int m = strlen(s1);
    int n = strlen(s2);

    if(m + n != strlen(s3))
        return false;

    bool dp[101][101] = {false};

    dp[0][0] = true;

    // First column
    for(int i = 1; i <= m; i++)
    {
        dp[i][0] = dp[i-1][0] &&
                   (s1[i-1] == s3[i-1]);
    }

    // First row
    for(int j = 1; j <= n; j++)
    {
        dp[0][j] = dp[0][j-1] &&
                   (s2[j-1] == s3[j-1]);
    }

    // Fill DP table
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] =
                (dp[i-1][j] && s1[i-1] == s3[i+j-1]) ||
                (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
    }

    return dp[m][n];
}