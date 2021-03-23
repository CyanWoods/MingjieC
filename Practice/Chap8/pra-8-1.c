/* 多个字符串的键盘打字练习（其二：打乱出题顺序“方法一”）*/

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getputch.h"

#define QNO		12		/* 题目数量 */

#define swap(type, x, y)	do { type t = x; x = y; y = t; } while (0)

int main(void)
{
	char *str[QNO] = {"book",   "computer", "default",  "comfort",
					  "monday", "power",    "light",    "music", 
					  "programming", "dog", "video",    "include"};
	int i, stage;
	int qno[QNO];					/* 出题顺序 */
	int ques[10];
	struct timespec start, end; 
    double time_elapsed;
	int cnt=1;

	init_getputch();
	srand(time(NULL));				/* 设定随机数的种子 */

	for (i = 0; i < QNO; i++)
		qno[i] = i;

	for (i = QNO - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		if (i != j)
			swap(int, qno[i], qno[j]);
	}
	for (i=0;i<10;i++)
	{
		ques[i]=qno[i];
	}

	printf("开始打字练习。\n");
	printf("按下空格键开始。\n");
	while (getch() != ' ')			/* 一直等待到 */
		;							/* 玩家按下空格键 */

	clock_gettime(CLOCK_REALTIME, &start);				/* 开始时间 */

	for (stage = 0; stage < 10; stage++) {
		int len = strlen(str[ques[stage]]); /* 字符串str[qno[stage]]的字符数量 */
			printf("%d\n",cnt++);
		for (i = 0; i < len; i++) {
			/* 显示str[qno[stage]] [i]之后的字符并把光标返回到开头 */
			printf("%s \r", &str[ques[stage]][i]);

			fflush(stdout);
			while (getch() != str[ques[stage]][i])
				;
		}
	}
	clock_gettime(CLOCK_REALTIME, &end);					/* 结束时间 */
	term_getputch();

	long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    time_elapsed = seconds + nanoseconds*1e-9;

    printf("用时%.1f秒。\n", time_elapsed);
 	return 0;
}
