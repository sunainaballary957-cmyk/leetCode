#include <stdlib.h>
#include <string.h>

char * reverseWords(char * s)
{
    int n = strlen(s);

    char *result = (char *)malloc((n + 1) * sizeof(char));

    int k = 0;
    int i = n - 1;

    while(i >= 0)
    {
        // Skip spaces
        while(i >= 0 && s[i] == ' ')
            i--;

        if(i < 0)
            break;

        // Find beginning of current word
        int j = i;

        while(j >= 0 && s[j] != ' ')
            j--;

        // Copy word
        for(int p = j + 1; p <= i; p++)
        {
            result[k++] = s[p];
        }

        // Add one space if more words remain
        while(j >= 0 && s[j] == ' ')
            j--;

        if(j >= 0)
            result[k++] = ' ';

        i = j;
    }

    result[k] = '\0';

    return result;
}