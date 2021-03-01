//使用while语句进行循环判断

#include <stdio.h>

int main()
{
	int no;
	int ans=7;

	printf("猜一个0到9之间的整数。\n\n");

	while (1)
	{
		printf("是多少呢：");
		scanf("%d",&no);

		if (no>ans)
			printf("\a你输入的值太大了。\n");
		else if (no<ans)
			printf("\a你输入的值太小了。\n");
		else	
			break;
	}
	printf("恭喜你猜对了。\n");
	return 0;
}
