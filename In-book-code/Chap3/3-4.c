
#include <ctype.h>
#include <stdio.h>
#include <limits.h>

void strdump(const char *s)
{
	while (*s) {
		int i;
		unsigned char x = (unsigned char)*s;

		printf("%c  ", isprint(x) ? x : ' ');	
		printf("%0*  ", (CHAR_BIT + 3) / 4);
		for (i = CHAR_BIT - 1; i >= 0; i--)		
			putchar(((x >> i) & 1U) ? '1' : '0');
		putchar('\n');
		s++;
	}
}

int main(void)
{
	puts("汉字");		strdump("汉字");		putchar('\n');

	puts("12中国话AB");	strdump("12中国话AB");	putchar('\n');

	return 0;
}
