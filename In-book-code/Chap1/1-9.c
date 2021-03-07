//利用sizeof() 显示数组的个数


#include <stdio.h>

int main(void)
{
	int i;
	int a[]={1,2,3,4,5};
	int na=sizeof(a)/sizeof(a[0]);

	printf("数组a的元素个数为：%d。\n",na);
	printf("%2d。\n",sizeof(a));
	printf("%2d。\n",sizeof(a[0]));

	for (i=0;i<na;i++)
		printf("a[%d]=%d",i,a[i]);
	return 0;
}

