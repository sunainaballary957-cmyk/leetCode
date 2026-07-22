/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int postIndex;

struct TreeNode* build(int* inorder, int* postorder, int left, int right)
{
    if(left > right)
        return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    root->val = postorder[postIndex--];
    root->left = NULL;
    root->right = NULL;

    int index = left;

    while(inorder[index] != root->val)
        index++;

    // Build right subtree first
    root->right = build(inorder, postorder, index + 1, right);
    root->left = build(inorder, postorder, left, index - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1);
}