//List 2-3 的“心算训练”程序显示的是进行10次加法运算所需要的时间。改写程序，令其能显示每次运算所需要的时间和运算的平均时间。


#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	int round=2;
	double his[round];
	double start[round];
	double stop[round];
	int stage;
	int a, b, c;			
	int x;					
	int n;					
	int i=0;

	srand(time(NULL));		

	for (stage = 0; stage < round; stage++)
	 {
		start[i]= (double)clock();				
		a = 10 + rand() % 9;		
		b = 10 + rand() % 9;		
		c = 10 + rand() % 9;	
		n = rand() % 5;			

		printf("%d%*s+%*s%d%*s+%*s%d：", a, n, "", n, "", b, n, "", n, "", c);

		do {
			scanf("%d", &x);
			if (x == a + b + c)
				break;
			printf("\a回答错误。请重新输入：");
		} while (1);
		stop[i]=(double)clock();
		his[i]=stop[i]-start[i];
		i++;
	}
	for (i=0;i<round;i++)
		printf("%f-%f=%f\n",stop[i],start[i],his[i]);

	double sum=0;
	double ave;
	for (i=0;i<round;i++)
	{
		sum=sum+his[i];
	}
	ave=sum/i;
	printf("%f",ave);
	return 0;
}
