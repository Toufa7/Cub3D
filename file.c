#include <stdio.h>

int main()
{
    int i = 0 ;
    int var = 0;
    while (i < 1080)
    {
        int var = i * ((700 - 1080) * ((700 > 1080) / 2));
        printf("Var => %d\n", var);
        printf("Var => %d\n", i);
        i++;
    }
}