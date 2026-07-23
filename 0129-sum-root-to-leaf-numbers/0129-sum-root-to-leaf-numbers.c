/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* root, int current)
{
    if(root == NULL)
        return 0;

    current = current * 10 + root->val;

    if(root->left == NULL && root->right == NULL)
        return current;

    return dfs(root->left, current) +
           dfs(root->right, current);
}

int sumNumbers(struct TreeNode* root)
{
    return dfs(root, 0);
}