/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 * Note: Both returned array and *columnSizes array must be malloc'ed.
 */

void backtrack(int* candidates, int candidatesSize, int target, int start,
               int* temp, int tempSize,
               int*** result, int* returnSize,
               int** returnColumnSizes)
{
    if (target == 0)
    {
        (*result)[*returnSize] = (int*)malloc(tempSize * sizeof(int));

        for (int i = 0; i < tempSize; i++)
            (*result)[*returnSize][i] = temp[i];

        (*returnColumnSizes)[*returnSize] = tempSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++)
    {
        if (candidates[i] > target)
            continue;

        temp[tempSize] = candidates[i];

        // i is used again because the same element can be reused
        backtrack(candidates, candidatesSize,
                  target - candidates[i], i,
                  temp, tempSize + 1,
                  result, returnSize,
                  returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes)
{
    int maxSize = 150;

    int** result = (int**)malloc(maxSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSize * sizeof(int));

    int temp[40];

    *returnSize = 0;

    backtrack(candidates, candidatesSize, target, 0,
              temp, 0,
              &result, returnSize,
              returnColumnSizes);

    return result;
}