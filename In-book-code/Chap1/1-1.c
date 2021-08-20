//一个最简单的分支代码


#include <stdio.h>
int main()
{
	int no;
	int ans=7;

	printf("猜一个一到九之间的整数\n\n");
	printf("你猜是多少呢？:");
	scanf("%d",&no);
	
	if (no>ans)
		printf("太大了，小一点。\n");
	else if (no<ans)
		printf("太小了，大一点。\n");
	else
		printf("你猜对了\n");

	return 0;
}
	
    