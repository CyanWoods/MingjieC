#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void random (int *y, int *m, int *d)
{
    *y = 2000 + rand() % 21;                                //年份在2000~2020之间
    *m = 1 + rand() % 12;                                   //月份在1~12之间

    if (*m==1 || *m==3 || *m==5 || *m==7 || *m==8 || *m==10 || *m==12)
        *d = 1 + rand() % 31;
    else if (*m==4 || *m==6 || *m==9 || *m==11)
        *d = 1 + rand() % 30;
    else {
        if ((*y%4==0 && *y%100!=0) || *y%400==0 )           //闰年二月
            *d = 1 + rand() % 29;
        else
            *d = 1 + rand() % 28;
    }
/*
    printf("正确答案是 %d 年 %d 月 %d 日。\n",*y,*m,*d);
*/
}

void judge (int y0, int m0, int d0, int y1, int m1, int d1)
{
    if (y1 < y0) {
        printf("年份靠后一点。\n");
        return;
    }
    else if (y1 > y0) {
        printf("年份靠前一点。\n");
        return;
    }
    else {
        if (m1 < m0) {
            printf("年份对了。月份靠后一点。\n");
            return;
        }
        else if (m1 > m0) {
            printf("年份对了。月份靠前一点。\n");
            return;
        }
        else {
            if (d1 < d0) {
                printf("年份和月份都对了。日期靠后一点。\n");
                return;
            }
            else if (d1 > d0) {
                printf("年份和月份都对了。日期靠前一点。\n");
                return;
            }
            else
                return;
        }
    }
}

int main(void)
{
	int no;
	int ans_y, ans_m, ans_d;
	int input_y, input_m, input_d;
	const int max_stage = 15;
	int remain = max_stage;

	srand(time(NULL));
	random(&ans_y,&ans_m,&ans_d);

	printf("请猜一个日期。\n");
	printf("年月日中间用空格隔开。\n");
	printf("年份在2000~2020之间。\n");

	do {
input:
        printf("\n还剩%d次机会！请输入答案：", remain);
		scanf("%d%d%d", &input_y, &input_m, &input_d);

		if ( (input_y>=2000 && input_y<=2020) && (input_m>=1 && input_m<=12) && (input_d>=1 && input_d <=31) ) {
            remain--;
            judge(ans_y, ans_m, ans_d, input_y, input_m, input_d);
		}
        else {
            printf("ERROR!\n");                       //输入错误
            goto input;
        }

	} while ( ( input_y != ans_y || input_m != ans_m || input_d != ans_d ) && remain > 0);

	if (remain == 0)
		printf("\a\n很遗憾，正确答案是 %d 年 %d 月 %d 日。\n",ans_y,ans_m,ans_d);
	else {
		printf("\n回答正确。\n");
		printf("您用了%d次猜中了。\n", max_stage - remain);
	}

	return 0;
}
