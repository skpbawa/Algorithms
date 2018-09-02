#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<regex.h>
#include <time.h>

char* getSubstr(char* txt, char *substr, int start, int length)
{
    int i, j;
    j = 0;
    for (i = start; i <= start + length - 1; i++)
    {
        substr[j] = txt[i];
        j++;
    }
    substr[j] = '\0';

}
int main()
{
    int i, reti;
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    char *txt = "ABABDABACDABABCABAB";
    char *pat = "ABABCABAB";

    // char* substr;
    // substr = (char*) malloc (sizeof(char) * 10);
    char **substr;
    substr = (char**) malloc (sizeof(char*) * 11);
    
    for (i = 0; i < 11; i++)
    {
        substr[i] = (char*) malloc (sizeof(char) * 10);
        getSubstr(txt, substr[i], i, 9);
    }
        
    regex_t regex2;
    for (i = 0; i < 11; i++)
    {
        // getSubstr(txt, substr, i, 9);
        regcomp(&regex2, substr[i], 0);
        // regcomp(&regex2, substr, 0);        
        reti = regexec(&regex2, "ABABCABAB", 0, NULL, 0);        
        if (!reti)
        {
            printf ("\n It occurs at index = %d", i);
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken is:   %f",cpu_time_used);
}