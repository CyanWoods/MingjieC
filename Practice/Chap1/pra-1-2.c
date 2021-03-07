#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main (void)	
{
	int r;
	int t=time(NULL);
	srand(t);
	r=rand();

	int a=r%10;
	
	printf("%d\n",t);	
	printf("%d %d\n",r,a);
	if (a==6)
		printf("大凶\n");
	else if (a==1)
		printf("中吉\n");
	else if (a==2)
		printf("小吉\n");
	else if (a==3)
		printf("吉\n");
	else if (a==4)
		printf("末吉\n");
	else if (a==5)
		printf("小凶\n");
	else 
		printf("大吉\n");
	return 0 ;
}
