//编写一个如字幕般显示字符串的函数。void telop (const char *s, int direction, int speed, int n);


#include <stdio.h>
#include <string.h>
#include <time.h>

//提供暂停若干毫秒功能的函数
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

//跑马灯函数
void telop(const char *s,int speed,int direction, int n)
{
    int i,j;
    int cnt=0;
    int len=strlen(s);

    for (j=0;j<len*n;j++)
    {
        putchar('\r');

        for (i=0;i<len;i++)
        {
            if (cnt+i<len)
                putchar(s[cnt+i]);
            else
                putchar(s[cnt+i-len]);
        }
    
    fflush(stdout);
    sleep(speed);

        if (direction==1)
        {
         if (cnt>0)
                cnt--;
         else
                cnt=len-1;
        }
         else if (direction==0)
     {
            if (cnt<len-1)
               cnt++;
            else
                cnt=0;
    }
    }
}

//主函数
int main(void)
{
    telop("Ice Bear Loves Isabel! ",500,0,10);
    return 0;
}