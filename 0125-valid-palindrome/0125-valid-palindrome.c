#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s)
{
    int left = 0;
    int right = strlen(s) - 1;

    while(left < right)
    {
        // Skip non-alphanumeric characters
        while(left < right &&
             !((s[left] >= 'A' && s[left] <= 'Z') ||
               (s[left] >= 'a' && s[left] <= 'z') ||
               (s[left] >= '0' && s[left] <= '9')))
        {
            left++;
        }

        while(left < right &&
             !((s[right] >= 'A' && s[right] <= 'Z') ||
               (s[right] >= 'a' && s[right] <= 'z') ||
               (s[right] >= '0' && s[right] <= '9')))
        {
            right--;
        }

        // Convert uppercase to lowercase
        char c1 = s[left];
        char c2 = s[right];

        if(c1 >= 'A' && c1 <= 'Z')
            c1 = c1 + 32;

        if(c2 >= 'A' && c2 <= 'Z')
            c2 = c2 + 32;

        // Compare
        if(c1 != c2)
            return false;

        left++;
        right--;
    }

    return true;
}