/**
 * Note: The returned value must be malloced, assume caller calls free().
 */

typedef struct Node
{
    int course;
    struct Node* next;
} Node;

bool canFinish(int numCourses, int** prerequisites,
               int prerequisitesSize, int* prerequisitesColSize)
{
    Node* graph[2000] = {NULL};
    int indegree[2000] = {0};

    // Build graph
    for(int i = 0; i < prerequisitesSize; i++)
    {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->course = course;
        newNode->next = graph[prereq];
        graph[prereq] = newNode;

        indegree[course]++;
    }

    int queue[2000];
    int front = 0, rear = 0;

    // Add all courses with indegree 0
    for(int i = 0; i < numCourses; i++)
    {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    int count = 0;

    while(front < rear)
    {
        int curr = queue[front++];
        count++;

        Node* temp = graph[curr];

        while(temp != NULL)
        {
            indegree[temp->course]--;

            if(indegree[temp->course] == 0)
                queue[rear++] = temp->course;

            temp = temp->next;
        }
    }

    return count == numCourses;
}