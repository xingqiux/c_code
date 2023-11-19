#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)
{
	int count = 0;
	char ch;
	while (count < 10)
	{
		ch = getchar();
		if (ch == '\n')
			continue;
		putchar(ch);
		count++;
	}
}