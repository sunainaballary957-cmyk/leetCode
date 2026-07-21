/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int preIndex = 0;

struct TreeNode* build(int* preorder, int* inorder, int left, int right)
{
    if(left > right)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[preIndex++];
    root->left = NULL;
    root->right = NULL;

    int index = left;

    while(inorder[index] != root->val)
        index++;

    root->left = build(preorder, inorder, left, index - 1);
    root->right = build(preorder, inorder, index + 1, right);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1);
}