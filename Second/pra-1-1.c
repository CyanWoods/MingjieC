#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)	
{	
	srand(time(NULL));
	int a=rand() % 7;
	
	printf("%d",a);
	if (a==0)
		printf("大吉\n");
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
		printf("大凶\n");
	return 0 ;
}
