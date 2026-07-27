#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isWord(char *s, int start, int len, char **wordDict, int wordDictSize)
{
    for(int i = 0; i < wordDictSize; i++)
    {
        if(strlen(wordDict[i]) != len)
            continue;

        if(strncmp(s + start, wordDict[i], len) == 0)
            return true;
    }

    return false;
}

bool wordBreak(char* s, char** wordDict, int wordDictSize)
{
    int n = strlen(s);

    bool dp[n + 1];

    for(int i = 0; i <= n; i++)
        dp[i] = false;

    dp[0] = true;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(dp[j] && isWord(s, j, i - j, wordDict, wordDictSize))
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
}