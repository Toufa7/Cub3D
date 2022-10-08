#include <unistd.h>
#include <string.h>
#include <stdio.h>

void    *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char   *block ,byte;

    byte = (unsigned char)c;
    block = (unsigned char *)s;
    i = -1;
    while (++i < n)
        block[i] = byte;
    return (block);
} 

int main ()
{
   int arr[5] = {1, 3, 3, 4, 5};
   int a;
   scanf("%d => ", &a);
   memset(arr, a, sizeof(int)*4);
   for (int i = 0; i < 5 ; i++)
        printf("%d\n", arr[i]);
}
