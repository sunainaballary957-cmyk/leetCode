/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root)
{
    if(root == NULL)
        return NULL;

    struct Node* queue[6001];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear)
    {
        int size = rear - front;
        struct Node* prev = NULL;

        for(int i = 0; i < size; i++)
        {
            struct Node* curr = queue[front++];

            if(prev != NULL)
                prev->next = curr;

            prev = curr;

            if(curr->left)
                queue[rear++] = curr->left;

            if(curr->right)
                queue[rear++] = curr->right;
        }

        prev->next = NULL;
    }

    return root;
}