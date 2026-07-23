/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

double* averageOfLevels(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;

    if(root == NULL)
        return NULL;

    double *result = (double*)malloc(10000 * sizeof(double));
    struct TreeNode* queue[10001];

    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear)
    {
        int size = rear - front;
        long long sum = 0;

        for(int i = 0; i < size; i++)
        {
            struct TreeNode* curr = queue[front++];

            sum += curr->val;

            if(curr->left)
                queue[rear++] = curr->left;

            if(curr->right)
                queue[rear++] = curr->right;
        }

        result[(*returnSize)++] = (double)sum / size;
    }

    return result;
}