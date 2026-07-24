/**
 * // Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */

struct Node* visited[101];

struct Node* dfs(struct Node* node)
{
    if(node == NULL)
        return NULL;

    if(visited[node->val] != NULL)
        return visited[node->val];

    struct Node* clone = (struct Node*)malloc(sizeof(struct Node));

    clone->val = node->val;
    clone->numNeighbors = node->numNeighbors;
    clone->neighbors = (struct Node**)malloc(node->numNeighbors * sizeof(struct Node*));

    visited[node->val] = clone;

    for(int i = 0; i < node->numNeighbors; i++)
    {
        clone->neighbors[i] = dfs(node->neighbors[i]);
    }

    return clone;
}

struct Node *cloneGraph(struct Node *s)
{
    for(int i = 0; i <= 100; i++)
        visited[i] = NULL;

    return dfs(s);
}