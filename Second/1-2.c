//继续猜数 这次进行循环判断

#include <stdio.h>

int main()
{
	int no;
	int ans=7;

	printf("请随便猜一个0到9之间的数字\n\n");
	
	do{
		printf("我选择这个数：");
		scanf("%d",&no);

		if (no>ans)
			printf("\a不对哦，你输入的数字大了。\n");
		else if (no<ans)
			printf("\a不对哦，你输入的数字小了。\n");
	}while (no!=ans);
	printf("你猜对了\n");
	return 0;
}
