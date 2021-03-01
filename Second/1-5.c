#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int retry;
	srand(time(NULL));
	printf("在这个编程环境中能够生成0-%d的随机数\n",RAND_MAX);
	do{
		printf("这次生成的数字为：%d",rand());
		printf("\n是否要再生成一次？\n \t (0) no (1)yes");
		scanf("%d",&retry);
	}while (retry==1);
	return 0;
}
		
