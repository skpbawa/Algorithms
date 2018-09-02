#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lps.h"

using namespace std;

void KMP(char *text, char *pattern, int *lps)
{
    int textIterator = 0, patIterator = 0;
    while (textIterator < strlen (text))
    {
        if (text [textIterator] == pattern [patIterator])
        {
            textIterator ++;
            patIterator ++;
            if (patIterator == strlen (pattern))
            {
                printf ("The Pattern exists at %d\n", (textIterator - patIterator));
                patIterator = lps [patIterator - 1];    
            }
        }
        else if (textIterator < strlen (text) && (text [textIterator] != pattern [patIterator]))
        {
            if (patIterator != 0)
                patIterator = lps [patIterator - 1];
            else
                textIterator ++;
        }

    }
}

int main()
{
    int patSize,textSize;
    printf ("Enter the length of the pattern and text : \n");
    scanf ("%d %d", &patSize, &textSize);

    char *pattern = (char *) malloc ( sizeof (char) * patSize);
    char *text = (char *) malloc ( sizeof (char) * textSize);
    int *lps = (int *) malloc ( sizeof (int) * patSize);   

    printf ("Enter the pattern and the text : \n");
    scanf ("%s %s", pattern, text);

    preprocessLPS (lps, pattern);

    KMP (text, pattern, lps);

    return 0;
}