
#include<stdio.h>

void onBit(unsigned int num,int n);
void offBit(unsigned  num,int n);
void invertBit(unsigned  num ,int n);
void print_binary(unsigned x) ;


int main()
{

    unsigned int x=2;
    print_binary(x);
    printf("\n\n");

    onBit(x,3);


    getchar();
    return 0;
}
void onBit(unsigned int num,int n)
{
    num = num | (1 << n);
    print_binary(num);


}

void offBit(unsigned int num,int n)
{
    num = num & (1 << n);
    print_binary(num);


}

void invertBit(unsigned int num,int n)
{
    num = num ^ (1 << n);
    print_binary(num);


}
void print_binary(unsigned x) 
{
    int bits = sizeof(x) * 4;
    for (int i = bits - 1; i >= 0; i--) {
        unsigned int bit = (x >> i) & 1;
        printf("%u", bit);
        if (i % 4 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}


