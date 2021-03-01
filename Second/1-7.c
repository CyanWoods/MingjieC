#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	srand(time(NULL));
	int ans=rand()%100;
	int no;
	int count=0;

	printf("已知目标数字为0-99之间的数字\n");
	printf("你要猜测这个数是多少\n");
	do{
		count++;
		printf("请输入数字：");
		scanf("%d",&no);

		if (no>ans)
			printf("你猜的有点大，再小一点看看\n");
		else if (no<ans)	
			printf("你猜的有点小，再大一点看看\n");
	}while(no!=ans &&count<10 );
	if (count<10)
		printf("你猜对了！\n");
	else
		printf("真遗憾，你超过了十步\n");
	return 0;
}


