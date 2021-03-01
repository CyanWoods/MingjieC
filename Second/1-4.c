#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int retry;

	printf("这个编程环境中能随机生成0到%d之间的随机数\n",RAND_MAX);

	do{
		printf("\n生成了随机数%d。\n",rand());
		printf("是否再来一次：（0）否（1）是：");
		scanf("%d",&retry);
	}while(retry==1);
	return 0;
}
