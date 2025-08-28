#include<stdio.h>


void  printFloat(float* f );

int  main()
{
    float a=5.26589;
    float b=444444.29335544;

    printFloat(&a);
    
    printFloat(&b);


    getchar();
    return 0;

}

void printFloat(float* f)
{
 int num = (int)(*f * 100);      // ضرب عدد در 100 و تبدیل به int
    int numf = num % 100;            // دو رقم اعشار

    if (numf < 0)                   // اگر عدد منفی بود اصلاح کن
        numf = -numf;

    num /= 100;                     // قسمت صحیح عدد

    printf("%d.%02d\n", num, numf); // %02d برای چاپ 2 رقم بعد اعشار با صفر پرکن
}