//利用数组显示每次的输入记录


#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_STAGE 10

int main (void)
{
	int i;
	int stage;
	int no;
	int ans;
	int num[MAX_STAGE];

	srand(time(NULL));
	ans=rand()%100;

	printf("请输入一个0-99之间的整数.\n\n");
	stage=0;

	do{
		printf("还有%d次机会\n",MAX_STAGE-stage);
		printf("你输入的值是：");
		scanf("%d",&no);
		num[stage++]=no;

		if (no>ans)
			printf("你输入的值有点大，再小一点。\n");
		else if (no<ans)
			printf("你输入的值有点小，再大一点。\n");
	}while (no!=ans && stage<MAX_STAGE);
	if (no==ans)
		printf("恭喜你在第%d步的时候猜到了答案\n",stage);
	else
		printf("真遗憾 你没有猜出来，答案是%d\n",ans);
	puts("\n--- 输入记录 ---");
	for (i=0;i<stage;i++)
		printf("%2d:%4d %+4d\n",i+1,num[i],num[i]-ans);
	return 0;
}


		

