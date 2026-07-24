/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int prev;
int minDiff;
bool first;

void inorder(struct TreeNode* root)
{
    if(root == NULL)
        return;

    inorder(root->left);

    if(first)
    {
        prev = root->val;
        first = false;
    }
    else
    {
        if(root->val - prev < minDiff)
            minDiff = root->val - prev;

        prev = root->val;
    }

    inorder(root->right);
}

int getMinimumDifference(struct TreeNode* root)
{
    first = true;
    minDiff = INT_MAX;

    inorder(root);

    return minDiff;
}