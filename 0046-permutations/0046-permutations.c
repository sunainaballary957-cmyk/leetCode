/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 * Note: Both returned array and *columnSizes array must be malloc'ed.
 */

void backtrack(int* nums, int numsSize, int* used, int* temp, int tempSize,
               int*** result, int* returnSize, int** returnColumnSizes) {

    if (tempSize == numsSize) {
        (*result)[*returnSize] = (int*)malloc(numsSize * sizeof(int));

        for (int i = 0; i < numsSize; i++)
            (*result)[*returnSize][i] = temp[i];

        (*returnColumnSizes)[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i])
            continue;

        used[i] = 1;
        temp[tempSize] = nums[i];

        backtrack(nums, numsSize, used, temp, tempSize + 1,
                  result, returnSize, returnColumnSizes);

        used[i] = 0;   // Backtrack
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int maxSize = 720;   // 6! = 720 (maximum permutations)

    int** result = (int**)malloc(maxSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(maxSize * sizeof(int));

    int used[6] = {0};
    int temp[6];

    *returnSize = 0;

    backtrack(nums, numsSize, used, temp, 0,
              &result, returnSize, returnColumnSizes);

    return result;
}