// lps [i] stands for longest proper prefix which is also the suffix of the pattern [0...i].

#include<string.h>

void preprocessLPS (int *lps, char *pattern)
{
    lps [0] = 0;
    int prefixCount = 0;
    int iterator = 1;
    
    while (iterator < strlen (pattern))
    {
        if (pattern [prefixCount] == pattern[iterator])
        {
            prefixCount ++;
            lps [iterator] = prefixCount;
            iterator ++;
        }
        else
        {
            if (prefixCount == 0)
            {
                lps [iterator] = 0;
                iterator ++;
            }
            else
            {
                prefixCount = lps [prefixCount - 1];
            }
        }
    }
}