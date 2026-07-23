/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    struct TreeNode *stack[100005];
    int top;
} BSTIterator;

void pushLeft(struct TreeNode* node, BSTIterator* obj)
{
    while(node != NULL)
    {
        obj->stack[++obj->top] = node;
        node = node->left;
    }
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root)
{
    BSTIterator* obj = (BSTIterator*)malloc(sizeof(BSTIterator));
    obj->top = -1;

    pushLeft(root, obj);

    return obj;
}

int bSTIteratorNext(BSTIterator* obj)
{
    struct TreeNode* node = obj->stack[obj->top--];

    if(node->right != NULL)
        pushLeft(node->right, obj);

    return node->val;
}

bool bSTIteratorHasNext(BSTIterator* obj)
{
    return obj->top != -1;
}

void bSTIteratorFree(BSTIterator* obj)
{
    free(obj);
}