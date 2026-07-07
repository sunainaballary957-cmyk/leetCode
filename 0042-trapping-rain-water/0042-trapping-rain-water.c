#include <stdlib.h>

int trap(int* height, int heightSize)
{
    if(heightSize == 0)
        return 0;

    int *leftMax = (int *)malloc(heightSize * sizeof(int));
    int *rightMax = (int *)malloc(heightSize * sizeof(int));

    leftMax[0] = height[0];

    // Build leftMax array
    for(int i = 1; i < heightSize; i++)
    {
        if(height[i] > leftMax[i - 1])
            leftMax[i] = height[i];
        else
            leftMax[i] = leftMax[i - 1];
    }

    rightMax[heightSize - 1] = height[heightSize - 1];

    // Build rightMax array
    for(int i = heightSize - 2; i >= 0; i--)
    {
        if(height[i] > rightMax[i + 1])
            rightMax[i] = height[i];
        else
            rightMax[i] = rightMax[i + 1];
    }

    int water = 0;

    // Calculate trapped water
    for(int i = 0; i < heightSize; i++)
    {
        int minHeight;

        if(leftMax[i] < rightMax[i])
            minHeight = leftMax[i];
        else
            minHeight = rightMax[i];

        water += minHeight - height[i];
    }

    free(leftMax);
    free(rightMax);

    return water;
}