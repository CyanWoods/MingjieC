/* 寻找幸运数字训练（其二：数字随机排列）*/

#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "getputch.h"   //这玩意儿在类unix环境下使用gcc编译的时候要添加-lcurses参数来调用里面的curses.h头文件

#define MAX_STAGE	2			/* 挑战次数 */
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int sleep(unsigned long x)				//引入一个老朋友
{
	clock_t c1 = clock(), c2;

	do {
		if ((c2 = clock()) == (clock_t)-1)
			return 0;
	} while (1000.0 * (c2 - c1) / CLOCKS_PER_SEC < x);
	return 1;
}

int main(void)
{
	int i, j, stage;
	int dgt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a[11];
	double jikan;				/* 时间 */
	struct timespec start, end;		/* 开始时间和结束时间 */

	init_getputch();
	srand(time(NULL));			/* 设定随机数的种子 */

	printf("请输入重复的数字。\n");
	printf("按下空格键开始。\n");
	fflush(stdout);
	while (getch() != ' ')
		;

	clock_gettime(CLOCK_REALTIME, &start);
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;		/* 生成随机数0~8 */
		char no;					/* 读取的值 */

		i = j = 0;
		while (i < 10) {			/* 复制时重复dgt[x] */
			a[j++] = dgt[i];
			if (i == x)
				a[j++] = dgt[i];
			i++;
		}

		for (i = 9; i > 0; i--)    /* 重新排列数组a */
		{			
			int j = rand() % (i + 1);
			if (i != j)
				swap(int, a[i], a[j]);
		}

		for (i = 0; i < 11; i++)		/* 显示所有元素 */
		{
			printf("%d", a[i]);
			sleep(500);
			fflush(stdout);
			printf("\b");
			printf("%s"," ");
			sleep(500);
			fflush(stdout);
		}
		printf(":");
		fflush(stdout);

		do {
			no = getch( );
			if (isprint(no)) {			/* 如果能显示的话 */
				putch(no);				/* 显示按下的键 */
				if (no != dgt[x] + '0')	/* 如果回答错误 */
					putch('\b');		/* 把光标往前退一格 */
				else
					printf("\n");		/* 换行 */
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');		/* 循环到玩家输入正确答案为止 */
	}
	clock_gettime(CLOCK_REALTIME, &end);

    long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    jikan = seconds + nanoseconds*1e-9;
     while (getch() != ' ')
		;
	term_getputch();

	printf("\n");
	printf("用时%.1f秒。\n", jikan);

	if (jikan > 25.0)
		printf("反应太慢了。\n");
	else if (jikan > 20.0)
		printf("反应有点慢呀。\n");
	else if (jikan > 17.0)
		printf("反应还行吧。\n");
	else
		printf("反应真快啊。\n");

	return 0;
}
