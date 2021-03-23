/* 一个字符串的键盘打字练习（其二：消去已输入的字符）*/

#include <time.h>
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

    clock_gettime(CLOCK_REALTIME, &start);

	for (i = 0; i < len; i++) {
		/* 显示str[i]以后的字符并把光标返回到开头 */
		printf("%s \r", &str[i]);

		fflush(stdout);
		while (getch() != str[i])
			;
	}

	clock_gettime(CLOCK_REALTIME, &end);

	term_getputch();

	long seconds = end.tv_sec - start.tv_sec;
    long nanoseconds = end.tv_nsec - start.tv_nsec;
    time_elapsed = seconds + nanoseconds*1e-9;

    printf("用时%.1f秒。\n", time_elapsed);

	return 0;
}