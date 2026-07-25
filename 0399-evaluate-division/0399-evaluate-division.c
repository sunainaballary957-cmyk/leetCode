/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXV 50

typedef struct
{
    int to;
    double weight;
} Edge;

Edge graph[MAXV][MAXV];
int degree[MAXV];

char vars[MAXV][6];
int varCount = 0;

int getIndex(char *s)
{
    for(int i = 0; i < varCount; i++)
    {
        if(strcmp(vars[i], s) == 0)
            return i;
    }

    strcpy(vars[varCount], s);
    return varCount++;
}

bool visited[MAXV];

double dfs(int src, int dest, double product)
{
    if(src == dest)
        return product;

    visited[src] = true;

    for(int i = 0; i < degree[src]; i++)
    {
        int next = graph[src][i].to;

        if(!visited[next])
        {
            double ans = dfs(next, dest,
                             product * graph[src][i].weight);

            if(ans != -1.0)
                return ans;
        }
    }

    return -1.0;
}

double* calcEquation(char*** equations,
                     int equationsSize,
                     int* equationsColSize,
                     double* values,
                     int valuesSize,
                     char*** queries,
                     int queriesSize,
                     int* queriesColSize,
                     int* returnSize)
{
    varCount = 0;

    for(int i = 0; i < MAXV; i++)
        degree[i] = 0;

    // Build Graph
    for(int i = 0; i < equationsSize; i++)
    {
        int u = getIndex(equations[i][0]);
        int v = getIndex(equations[i][1]);

        graph[u][degree[u]].to = v;
        graph[u][degree[u]].weight = values[i];
        degree[u]++;

        graph[v][degree[v]].to = u;
        graph[v][degree[v]].weight = 1.0 / values[i];
        degree[v]++;
    }

    double *result = (double *)malloc(sizeof(double) * queriesSize);

    *returnSize = queriesSize;

    for(int i = 0; i < queriesSize; i++)
    {
        int u = -1, v = -1;

        for(int j = 0; j < varCount; j++)
        {
            if(strcmp(vars[j], queries[i][0]) == 0)
                u = j;

            if(strcmp(vars[j], queries[i][1]) == 0)
                v = j;
        }

        if(u == -1 || v == -1)
        {
            result[i] = -1.0;
            continue;
        }

        for(int j = 0; j < MAXV; j++)
            visited[j] = false;

        result[i] = dfs(u, v, 1.0);
    }

    return result;
}