/* 寻找重复数字训练（其二：实时键盘输入）*/

#include <ctype.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "getputch.h"

#define MAX_STAGE	3					/* 挑战次数 */
#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	int i, j, x, stage;
	int dgt[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	char a[15]={" "};
	double jikan;						/* 时间 */
	clock_t start, end;					/* 开始时间和结束时间 */

	init_getputch();
	srand(time(NULL));					/* 设定随机数的种子 */

	printf("请输入缺少的数字。\n");
	printf("按下空格键开始。\n");
	fflush(stdout);
	while (getch() != ' ')
		;

	start = clock();
	for (stage = 0; stage < MAX_STAGE; stage++) {
		int x = rand() % 9;		/* 生成随机数0～8 */
		int no;					/* 已读取的值 */

		i = j = 0;
		while (i < 9) {			/* 复制时跳过dgt[x] */
			if (i != x)
				a[j++] = dgt[i]+'0';
			i++;
		}

		for (i = 14; i > 0; i--) {	/* 重新排列数组a */
			int j = rand() % (i + 1);
			if (i != j)
				swap(char, a[i], a[j]);
		}

		for (i=0;i<3;i++)
		{
			for (int p=0;p<5;p++)
			{
				printf("\t%c ", a[p+i*5]);
			}
			printf("\n");
		}
		printf("：");
		fflush(stdout);

		do {
			no = getch();
			memset(a, 0, sizeof a);
			if (isprint(no))			/* 如果能显示的话 */
			 {
				putch(no);				/* 显示按下的键 */
				if (no != dgt[x] + '0')	/* 如果回答错误 */
					putch('\b');		/* 把光标往前退一格 */
				else
					printf("\n");		/* 换行 */
				fflush(stdout);
			}
		} while (no != dgt[x] + '0');
	}
	end = clock();

	jikan = (double)(end - start) / CLOCKS_PER_SEC*1000;

	
	printf("%.1f秒。%.1f秒\n", (double)start,(double)end);
	printf("用时%.1f秒。\n", jikan);

	if (jikan > 25.0)
		printf("反应太慢了。\n");
	else if (jikan > 20.0)
		printf("反应有点慢呀。\n");
	else if (jikan > 17.0)
		printf("反应还行吧。\n");
	else
		printf("反应真快啊。\n");

	while (getch() != ' ')
		;
	term_getputch();
	
	return 0;
}
