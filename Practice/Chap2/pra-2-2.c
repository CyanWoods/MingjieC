//编写一个函数，令其能从字符串开头逐一显示字符。 void gput (const char *s, int speed);


#include <stdio.h>
#include <string.h>
#include <time.h>

int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

void gput(const char *s,int speed)
{
    int len=strlen(s);
    int i;
    for(i=0;i<len;i++)
    {
        putchar(s[i]);
        fflush(stdout);
        sleep(speed);
    }
}

int main(void)
{
    gput("Ice Bear Loves Isabel!",100);
    return 0;
}