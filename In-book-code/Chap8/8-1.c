/* 一个字符串的键盘打字练习（其一）*/

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "getputch.h"

int main(void)
{
	int 	i;
	char	*str = "How do you do?";	/* 要输入的字符串 */
	int 	len = strlen(str);			/* 字符串str的字符数量 */
	struct timespec start, end; 
    double time_elapsed;

	init_getputch();

	printf("请照着输入。\n");
	printf("%s\n", str);				/* 显示要输入的字符串 */
	fflush(stdout);

	clock_gettime(CLOCK_REALTIME, &start);
	for (i = 0; i < len; i++) {
		int ch;

		do {
			ch = getch();			/* 从键盘读取信息 */
			if (isprint(ch)) {
				putch(ch);			/* 显示按下的键 */
				if (ch != str[i])	/* 如果按错了键 */
					putch('\b');	/* 把光标往前退一格   */
			}
		} while (ch != str[i]);
	}
	clock_gettime(CLOCK_REALTIME, &end);						/* 结束时间 */
	term_getputch();

	long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    time_elapsed = seconds + nanoseconds*1e-9;

    printf("用时%.1f秒。\n", time_elapsed);
	
	return 0;
}
