#include <stdbool.h>

bool isIsomorphic(char *s, char *t)
{
    int mapST[256] = {0};
    int mapTS[256] = {0};

    for(int i = 0; s[i] != '\0'; i++)
    {
        unsigned char ch1 = s[i];
        unsigned char ch2 = t[i];

        if(mapST[ch1] == 0 && mapTS[ch2] == 0)
        {
            mapST[ch1] = ch2;
            mapTS[ch2] = ch1;
        }
        else
        {
            if(mapST[ch1] != ch2 || mapTS[ch2] != ch1)
                return false;
        }
    }

    return true;
}