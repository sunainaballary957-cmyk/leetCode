int lengthOfLIS(int* nums, int numsSize)
{
    int dp[2500];
    int maxLength = 1;

    for(int i = 0; i < numsSize; i++)
        dp[i] = 1;

    for(int i = 1; i < numsSize; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
            }
        }

        if(dp[i] > maxLength)
            maxLength = dp[i];
    }

    return maxLength;
}