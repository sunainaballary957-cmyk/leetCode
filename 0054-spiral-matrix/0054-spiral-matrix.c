#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int *result = (int *)malloc(rows * cols * sizeof(int));

    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;

    int k = 0;

    while(top <= bottom && left <= right)
    {
        // Left to Right
        for(int i = left; i <= right; i++)
        {
            result[k++] = matrix[top][i];
        }
        top++;

        // Top to Bottom
        for(int i = top; i <= bottom; i++)
        {
            result[k++] = matrix[i][right];
        }
        right--;

        // Right to Left
        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)
            {
                result[k++] = matrix[bottom][i];
            }
            bottom--;
        }

        // Bottom to Top
        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)
            {
                result[k++] = matrix[i][left];
            }
            left++;
        }
    }

    *returnSize = k;
    return result;
}