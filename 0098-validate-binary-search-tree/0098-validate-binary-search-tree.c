/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

long long prev;
bool first;

bool inorder(struct TreeNode* root)
{
    if(root == NULL)
        return true;

    if(!inorder(root->left))
        return false;

    if(!first && root->val <= prev)
        return false;

    prev = root->val;
    first = false;

    return inorder(root->right);
}

bool isValidBST(struct TreeNode* root)
{
    first = true;
    prev = 0;

    return inorder(root);
}