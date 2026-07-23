/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int leftHeight(struct TreeNode* root)
{
    int h = 0;

    while(root)
    {
        h++;
        root = root->left;
    }

    return h;
}

int rightHeight(struct TreeNode* root)
{
    int h = 0;

    while(root)
    {
        h++;
        root = root->right;
    }

    return h;
}

int countNodes(struct TreeNode* root)
{
    if(root == NULL)
        return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if(lh == rh)
        return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}