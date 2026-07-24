/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int count;
int answer;

void inorder(struct TreeNode* root, int k)
{
    if(root == NULL)
        return;

    inorder(root->left, k);

    count++;

    if(count == k)
    {
        answer = root->val;
        return;
    }

    inorder(root->right, k);
}

int kthSmallest(struct TreeNode* root, int k)
{
    count = 0;
    answer = 0;

    inorder(root, k);

    return answer;
}