//!代码来源于CSDN：https://blog.csdn.net/Isabel_Bei/article/details/107068548
//List 2-5 是一个用秒数来表示程序开始后经过的时间的程序。请改写程序，令其不仅能用秒数，还能用时钟数来表示时间。

#include <time.h>
#include <stdio.h>

/*--- 等待x毫秒 ---*/
int sleep(unsigned long x)
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)	/* 错误 */
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int 	i;
	clock_t	c;

	for (i = 10; i > 0; i--) {		/* 倒数 */
		printf("\r%2d", i);
		fflush(stdout);
		sleep(1000);				/* 暂停1秒 */
	}
	printf("\r\aFIRE!!\n");

	c = clock();
	printf("程序开始运行后经过了%.1f秒。\n时钟数为%.1f。\n",
									  (double)c / CLOCKS_PER_SEC,(double)c);
	return 0;
}