#include <stdbool.h>
#include <string.h>

bool wordPattern(char *pattern, char *s)
{
    char mapChar[26][301] = {{0}};
    char words[300][301];
    int wordCount = 0;

    int i = 0;

    // Split string into words
    while(s[i] != '\0')
    {
        int j = 0;

        while(s[i] != ' ' && s[i] != '\0')
        {
            words[wordCount][j++] = s[i++];
        }

        words[wordCount][j] = '\0';
        wordCount++;

        if(s[i] == ' ')
            i++;
    }

    // Pattern length must equal number of words
    if(strlen(pattern) != wordCount)
        return false;

    // Check mappings
    for(i = 0; i < wordCount; i++)
    {
        int index = pattern[i] - 'a';

        // Character not mapped yet
        if(mapChar[index][0] == '\0')
        {
            // Check if another character already maps to this word
            for(int k = 0; k < 26; k++)
            {
                if(strcmp(mapChar[k], words[i]) == 0)
                    return false;
            }

            strcpy(mapChar[index], words[i]);
        }
        else
        {
            if(strcmp(mapChar[index], words[i]) != 0)
                return false;
        }
    }

    return true;
}