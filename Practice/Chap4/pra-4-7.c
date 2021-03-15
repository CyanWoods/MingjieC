#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main (void)
{
	int count=0;
	int ans;
	int inp;
	int max_att=20;

	int t=time(NULL);
	srand(t);

	int x[4]={0};
	int i, j, val;

	for (i = 0; i < 4; i++) {
		do {
			val = rand() % 8;			/* 0~7的随机数 */
			for (j = 0; j < i; j++)		/* 是否已获得此数值 */
				if (val == x[j])
					break;
		} while (j < i);		/* 循环直至获得不重复的数值 */
		x[i] = val;
	}
    ans =1000*x[0]+100*x[1]+10*x[2]+x[3];
	do{
		count++;
		printf("你还有%d次机会\n",max_att-count+1);
		printf("随便猜一个0到987之间三个数字不重复的数。\n");
		printf("你猜的是：\n");
		scanf("%d",&inp);
		if (inp>ans)
			printf("太大了，试试小一点的。\n");
		else if (inp<ans)
			printf("太小了，试试大一点的。\n");
	}while(inp!=ans && count<max_att);
	if (count>max_att)
		printf("很遗憾，你没有在指定次数内猜到答案。\n");
	else if (count<max_att){
		printf("恭喜你猜到了答案\n");
		printf("你尝试了%d次\n",count);

	}
	return 0;
}