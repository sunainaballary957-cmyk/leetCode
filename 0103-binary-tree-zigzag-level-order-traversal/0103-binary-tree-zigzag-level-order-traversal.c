/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;

    if(root == NULL)
    {
        *returnColumnSizes = NULL;
        return NULL;
    }

    int **result = (int**)malloc(2000 * sizeof(int*));
    *returnColumnSizes = (int*)malloc(2000 * sizeof(int));

    struct TreeNode* queue[2001];
    int front = 0, rear = 0;

    bool leftToRight = true;

    queue[rear++] = root;

    while(front < rear)
    {
        int size = rear - front;

        result[*returnSize] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[*returnSize] = size;

        for(int i = 0; i < size; i++)
        {
            struct TreeNode* curr = queue[front++];

            int index;

            if(leftToRight)
                index = i;
            else
                index = size - 1 - i;

            result[*returnSize][index] = curr->val;

            if(curr->left)
                queue[rear++] = curr->left;

            if(curr->right)
                queue[rear++] = curr->right;
        }

        leftToRight = !leftToRight;
        (*returnSize)++;
    }

    return result;
}