/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes.
 * Note: Both returned array and *columnSizes array must be malloc'ed.
 */

void backtrack(int start, int n, int k, int *temp, int tempSize,
               int ***result, int *returnSize, int **returnColumnSizes) {

    if (tempSize == k) {
        (*result)[*returnSize] = (int *)malloc(k * sizeof(int));
        for (int i = 0; i < k; i++)
            (*result)[*returnSize][i] = temp[i];

        (*returnColumnSizes)[*returnSize] = k;
        (*returnSize)++;
        return;
    }

    for (int i = start; i <= n; i++) {
        temp[tempSize] = i;
        backtrack(i + 1, n, k, temp, tempSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {

    int maxSize = 200000;   // Enough for n <= 20

    int **result = (int **)malloc(maxSize * sizeof(int *));
    *returnColumnSizes = (int *)malloc(maxSize * sizeof(int));

    int temp[20];

    *returnSize = 0;

    backtrack(1, n, k, temp, 0,
              &result, returnSize, returnColumnSizes);

    return result;
}