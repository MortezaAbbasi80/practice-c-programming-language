#include<stdio.h>
#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#endif


int main()
{
    char c;
    while ((c=getchar())!=EOF)
    {
#ifdef _WIN32
        Sleep(1);
#else
        usleep(1000);
#endif
        putchar(c);
        fflush(stdout);
    }




    
}