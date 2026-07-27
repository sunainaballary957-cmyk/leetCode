int max(int a, int b)
{
    return (a > b) ? a : b;
}

int rob(int* nums, int numsSize)
{
    if(numsSize == 1)
        return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);

    for(int i = 2; i < numsSize; i++)
    {
        int current = max(prev1, prev2 + nums[i]);
        prev2 = prev1;
        prev1 = current;
    }

    return prev1;
}