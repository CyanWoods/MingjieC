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

void bput(const char *s,int d,int e, int n)
{
    int len=strlen(s);
    int i,j;

    for(i=0;i<n;i++)
    {
        printf("\r%s",s);
        fflush(stdout);
        sleep(d);

        putchar('\r');              //打印完，等完，就把光标挪到第一行准备打印等长空格。
        for (j=0;j<len;j++)
        {
            printf(" ");
            fflush(stdout);
        } 
        sleep(e);
    }
}

int main(void)
{
    bput("Ice Bear Loves Isabel!",500,200,10);
    return 0;
}