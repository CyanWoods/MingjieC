//编写一个“猜数游戏”，让目标数字是一个在-999和999之间的整数。同时还需思考应该把玩家最多可输入的次数定在多少合适


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
	ans=(rand()%1999)-999;
	
	do{
		count++;
		printf("你还有%d次机会\n",max_att-count+1);
		printf("随便猜一个-999到999之间的数。\n");
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

