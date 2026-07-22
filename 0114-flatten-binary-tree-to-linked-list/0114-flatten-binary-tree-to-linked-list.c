/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root)
{
    if(root == NULL)
        return;

    flatten(root->left);
    flatten(root->right);

    struct TreeNode* leftTree = root->left;
    struct TreeNode* rightTree = root->right;

    root->left = NULL;
    root->right = leftTree;

    struct TreeNode* curr = root;

    while(curr->right != NULL)
        curr = curr->right;

    curr->right = rightTree;
}