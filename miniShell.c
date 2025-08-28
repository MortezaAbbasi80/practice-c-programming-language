#include <stdio.h>

void miniShell();

int main(void)
{
    miniShell();
    return 0;
}

void miniShell()
{
    int flag = 0;   
    char c;

    printf("MiniShell> ");

    while ((c = getchar()) != EOF)
    {
        if (flag == 0 && c == 'e') {
            flag = 1;
        }
        else if (flag == 1 && c == 'x') {
            flag = 2;
        }
        else if (flag == 2 && c == 'i') {
            flag = 3;
        }
        else if (flag == 3 && c == 't') {
            int next = getchar();
            if (next == '\n' || next == EOF) {
                break; 
            } else {
                putchar('e');
                putchar('x');
                putchar('i');
                putchar(c);
                putchar(next);
                flag = 0;
            }
        }
        else {
          
            if (flag > 0) {
               
                if (flag >= 1) putchar('e');
                if (flag >= 2) putchar('x');
                if (flag >= 3) putchar('i');
            }
            putchar(c);
            flag = 0; 
        }

        if (c == '\n' && flag == 0) {
            printf("MiniShell> ");
        }
    }
}
