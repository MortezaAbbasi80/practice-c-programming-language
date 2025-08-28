#include<stdio.h>


char* strstr(char* haystack ,  char* needle);
int startsWith(char* a, char* b);
enum 
{
    BELL='\a',VTAB='\v'
};
int  main()
{
    char buff[100];
    int size=0;
    char c;
    while (((c=getchar())!=EOF&&size<100))
    {
        buff[size]=c;
        size++;
    }
    buff[size]='\0';
    char* bell=strstr(buff,"BELL");
    char* vtab=strstr(buff,"VTAB");
    if(bell)
    {
        *bell=BELL;
        *(++bell)=' ';
        *(++bell)=' ';
        *(++bell)=' ';
    }
    if(vtab)
    {
        *vtab=VTAB;
        *(++vtab)=' ';
        *(++vtab)=' ';
        *(++vtab)=' ';
    }
    

    printf("Text> %s",buff);



    getchar();
    return 0;
    
}





char* strstr(char* haystack ,  char* needle)
{

    if (*needle == '\0')
    return haystack;

    if (haystack == NULL || needle == NULL)
        return NULL;
    while (*haystack)
    {
        if(startsWith(haystack,needle))
            return haystack;
        else
            haystack++;
    }

    return NULL;
    
}



int startsWith(char* a, char* b)
{
    if (a == NULL || b == NULL)
        return 0;

    while (*b)
    {
        if (*a != *b)
            return 0;
        a++;
        b++;
    }

    return 1;
}