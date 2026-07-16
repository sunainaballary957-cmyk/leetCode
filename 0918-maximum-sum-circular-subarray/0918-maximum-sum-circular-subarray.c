int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int maxSubarraySumCircular(int* nums, int numsSize)
{
    int totalSum = nums[0];

    int maxSum = nums[0];
    int currentMax = nums[0];

    int minSum = nums[0];
    int currentMin = nums[0];

    for(int i = 1; i < numsSize; i++)
    {
        totalSum += nums[i];

        currentMax = max(nums[i], currentMax + nums[i]);
        maxSum = max(maxSum, currentMax);

        currentMin = min(nums[i], currentMin + nums[i]);
        minSum = min(minSum, currentMin);
    }

    // All elements are negative
    if(maxSum < 0)
        return maxSum;

    return max(maxSum, totalSum - minSum);
}