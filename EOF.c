#include <stdio.h>

int main()
{
    int countWord = 0;
    int countLine = 0;
    int countChar = 0;
    char pre = ' ';
    char c;

    while ((c = getchar()) != EOF)
    {
        countChar++;

        if ((pre == ' ' || pre == '\t' || pre == '\n') && (c != ' ' && c != '\t' && c != '\n'))
        {
            countWord++;
        }

        if (c == '\n')
        {
            countLine++;
        }

        pre = c;
    }

    printf("\nchar count: %d\nword count: %d\nline count: %d\n\n", countChar, countWord, countLine);

    return 0;
}
