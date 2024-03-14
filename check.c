#include <stdio.h>
#include <string.h>

void int_to_str(int val, char** str_num);

int main()
{
    int a = 134;
    char a1[4];
    int_to_str(a, (char**) &a1);
    printf("%s", a1);

}


void int_to_str(int val, char** str_num)
{

    if (val < 0)
    {
        printf("beda, we dont work with negative \n");
        return;
    }


    if (val == 0)
    {
        *str_num[2] = 0 + '0';    
    }


    int a = val;
    
    int hund = val / 100;
    int dec  = (val / 10) / 10;
    int unit = val % 10;

    if (hund)
    {
        *str_num[0] = hund + '0';
    }

    if (dec)
    {
        *str_num[1] = dec + '0';
    }
    if (unit)
    {
        *str_num[2] = unit + '0';
    }

}
