#include <stdio.h>
#include <string.h>

void *memset(void *b, int c, size_t len)
{
	int i;

	i = 0;
	while (i < len)
	{
		(unsigned char *)b[i] = 	c;
		i++;
	}
}

int main()
{
	int s[] ={0,1,2,3,4};
	memset(s,5, sizeof(int) * 3);
	for (int i = 0; i < 5; i++)
		printf("%d\n", s[i]);
}
