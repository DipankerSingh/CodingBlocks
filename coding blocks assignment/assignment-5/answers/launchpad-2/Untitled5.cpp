#include <stdio.h>
#include <string.h>

int main()
{
    char string[] = "What are you looking at";
    int i, n = strlen(string);

    int tail = n-1;
    for(i=n-1;i>=0;i--)
    {
        if(string[i] == ' ' || i == 0)
        {
            int cursor = (i==0? i: i+1);
            while(cursor <= tail)
                printf("%c", string[cursor++]);
            printf(" ");
            tail = i-1;
        }
    }
    return 0;
}
