int minSubArrayLen(int target, int* nums, int numsSize)
{
    int left = 0;
    int sum = 0;
    int minLength = numsSize + 1;

    for(int right = 0; right < numsSize; right++)
    {
        sum += nums[right];

        while(sum >= target)
        {
            int length = right - left + 1;

            if(length < minLength)
                minLength = length;

            sum -= nums[left];
            left++;
        }
    }

    if(minLength == numsSize + 1)
        return 0;

    return minLength;
}