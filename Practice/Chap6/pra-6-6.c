/*
注：
不输入参数：显示 当前年份+当前月份
输入1个参数：显示 当年年份+输入月份
输入2个参数：显示 输入月份+输入年份
输入3个参数：显示 输入年份的输入月份1~输入月份2
输入4个参数：显示 输入年份1的输入月份1~输入年份2的输入月份2
*/

#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*--- 各个月份的天数 ---*/
int mday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*--- year年month月day日是星期几 ---*/
int dayofweek(int year, int month, int day)
{
	if (month == 1 || month == 2) {
		year--;
		month += 12;
	}
	return (year + year/4 - year/100 + year/400 + (13*month+8)/5 + day) % 7;
}

/*--- year年是闰年吗？（0···平年/1···闰年） ---*/
int is_leap(int year)
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/*--- year年month月的天数（28～31） ---*/
int monthdays(int year, int month)
{
	if (month-- != 2)
		return mday[month];
	return mday[month] + is_leap(year);
}

/*--- 把y年m月的日历存入二维数组s中 ---*/
void make_calendar(int y, int m, char s[7][22])
{
	int i, k;
	int wd = dayofweek(y, m, 1);
	int mdays = monthdays(y, m);
	char tmp[4];

	sprintf(s[0], "%10d / %02d      ", y, m);

	for (k = 1; k < 7; k++)
		s[k][0] = '\0';

	k = 1;
	sprintf(s[k], "%*s", 3 * wd, "");

	for (i = 1; i <= mdays; i++) {
		sprintf(tmp, "%3d", i);
		strcat(s[k], tmp);
		if (++wd % 7 == 0)
			k++;
	}

	if (wd % 7 == 0)
		k--;
	else {
		for (wd %= 7; wd < 7; wd++)
			strcat(s[k], "   ");
	}
	while (++k < 7)
		sprintf(s[k], "%21s", "");
}

/*--- 把存在三维数组sbuf中的日历横向排列n个并显示 ---*/
void print(char sbuf[3][7][22], int n)
{
	int i, j;

	for (i = 0; i < n; i++)
	    printf("%s   ", sbuf[i][0]);
    putchar('\n');

	for (i = 0; i < n; i++)
		printf(" 日 一 二 三 四 五 六   ");
	putchar('\n');

	for (i = 0; i < n; i++)
		printf("----------------------  ");
	putchar('\n');

	for (i = 1; i < 7; i++) {
		for (j = 0; j < n; j++)
			printf("%s   ", sbuf[j][i]);
		putchar('\n');
	}
	putchar('\n');
}

/*--- 显示一段时间的日历 ---*/
void put_calendar_2(int y1, int m1, int y2, int m2)
{
    int y = y1;
	int m = m1;
	int n = 0;
	char sbuf[3][7][22];

	while (y <= y2) {
		if (y == y2 && m > m2) break;
		make_calendar(y, m, sbuf[n++]);
		if (n == 3) {
			print(sbuf, n);
			n = 0;
		}
		m++;
		if (m == 13 && y < y2) {
			y++;
			m = 1;
		}
	}
	if (n)
		print(sbuf, n);
}

/*--- 显示y年m月的日历 ---*/
void put_calendar(int y, int m)
{
	int i;
	int wd = dayofweek(y, m, 1);
	int mdays = monthdays(y, m);

	printf(" 日 一 二 三 四 五 六 \n");
	printf("----------------------\n");

	printf("%*s", 3 * wd, "");

	for (i = 1; i <= mdays; i++) {
		printf("%3d", i);
		if (++wd % 7 == 0)
			putchar('\n');
	}
	if (wd % 7 != 0)
		putchar('\n');
}

/*--- 比较字符串开头的n个字符（不区分大小写） ---*/
int strncmpx(const char *s1, const char *s2, size_t n)
{
    int x=n;
	while (toupper(*s1) && toupper(*s2)) {
		if (toupper(*s1) != toupper(*s2))
			return (unsigned char)*s1 - (unsigned char)*s2;
		s1++;
		s2++;
		x--;
	}
	if (x<=0 && *s2=='\0')        //见上个习题
        return 0;
	else
        return -1;
}

/*--- 从字符串中获取月份的值 ---*/
int get_month(char *s)
{
	int i;
	int m;
	char *month[] = {"", "January", "February", "March", "April",
					 "May", "June", "July", "August", "September",
					 "October", "November", "December"};

	m = atoi(s);
	if (m >= 1 && m <= 12)
		return m;

	for (i = 1; i <= 12; i++)
		if (strncmpx(month[i], s, 3) == 0)
			return i;

	return -1;
}

int main(int argc, char *argv[])
{
	int y, m;
	int y1, y2, m1, m2;
	time_t t = time(NULL);
	struct tm *local = localtime(&t);

	y = local->tm_year + 1900;
	m = local->tm_mon + 1;
                                                           //分情况讨论：
	if (argc == 2) {                                       //情况1：输入一个参数，即运行时年份+输入月份，与书中示例代码相同
		m = get_month(argv[1]);
		if (m < 0 || m > 12) {
			fprintf(stderr, "月份的值不正确。\n");
			return 1;
		}
		printf("%d年%d月\n\n", y, m);
        put_calendar(y, m);
	}
	else if (argc == 3) {                                  //情况2：输入两个参数，即输入月份+年份，与书中示例代码相同
	    m = get_month(argv[1]);
		if (m < 0 || m > 12) {
			fprintf(stderr, "月份的值不正确。\n");
			return 1;
		}

		y = atoi(argv[2]);
		if (y < 0) {
			fprintf(stderr, "年份的值不正确。\n");
			return 1;
		}
		printf("%d年%d月\n\n", y, m);
        put_calendar(y, m);
	}
	else if (argc == 4) {                                   //情况3：输入三个参数，年份+月份1+月份2，显示一段时间的日历，可参考书上示例代码6-12。
        y = atoi(argv[1]);
		if (y < 0) {
			fprintf(stderr, "年份的值不正确。\n");
			return 1;
		}

		m1 = get_month(argv[2]);
		if (m1 < 0 || m1 > 12) {
			fprintf(stderr, "月份的值不正确。\n");
			return 1;
		}

		m2 = get_month(argv[3]);
		if (m2 < 0 || m2 > 12) {
			fprintf(stderr, "月份的值不正确。\n");
			return 1;
		}

		if (m1 > m2) {
            fprintf(stderr, "输入有误无法显示。\n");
            return 1;
		}
		printf("%d年%d月到%d月\n\n", y, m1, m2);
        put_calendar_2(y, m1, y, m2);
	}
	else if (argc == 5) {                                    //情况4：输入四个参数，年份1+年份2+月份1+月份2，显示一段时间的日历，可参考书上示例代码6-12。
        y1 = atoi(argv[1]);
		if (y1 < 0) {
			fprintf(stderr, "年份的值不正确。\n");
			return 1;
		}

		m1 = get_month(argv[2]);
		if (m < 0 || m > 12) {
			fprintf(stderr, "月份的值不正确。\n");
			return 1;
		}

		y2 = atoi(argv[3]);
		if (y2 < 0) {
			fprintf(stderr, "年份的值不正确。\n");
			return 1;
		}

		m2 = get_month(argv[4]);
		if (m2 < 0 || m2 > 12) {
			fprintf(stderr, "月份的值不正确。\n");
			return 1;
		}

		if (y1 > y2) {
            fprintf(stderr, "输入有误无法显示。\n");
            return 1;
		}
		else {
            if (m1 > m2) {
                fprintf(stderr, "输入有误无法显示。\n");
                return 1;
            }
            else {
                printf("%d年%d月到%d年%d月\n\n", y1, m1, y2, m2);
                put_calendar_2(y1, m1, y2, m2);
            }
		}
	}
    else {                                                    //情况5：不输入参数，显示当前时间
        printf("%d年%d月\n\n", y, m);
        put_calendar(y, m);
    }

	return 0;
}