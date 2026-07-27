#include <stdlib.h>
#include <string.h>

char * simplifyPath(char * path)
{
    char **stack = (char **)malloc(3000 * sizeof(char *));
    int top = -1;

    char *token = strtok(path, "/");

    while(token != NULL)
    {
        if(strcmp(token, ".") == 0)
        {
            // Ignore current directory
        }
        else if(strcmp(token, "..") == 0)
        {
            if(top >= 0)
                top--;
        }
        else if(strlen(token) > 0)
        {
            stack[++top] = token;
        }

        token = strtok(NULL, "/");
    }

    char *result = (char *)malloc(3001);
    result[0] = '\0';

    if(top == -1)
    {
        strcpy(result, "/");
        free(stack);
        return result;
    }

    for(int i = 0; i <= top; i++)
    {
        strcat(result, "/");
        strcat(result, stack[i]);
    }

    free(stack);
    return result;
}