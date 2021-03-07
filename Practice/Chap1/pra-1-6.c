#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	srand(time(NULL));
	int usr_level;
	int devide_num;
	int max;
	int count=0;

	printf("choose game level (0)0-9; (1)0-99; (2)0-999; (3)0-9999");
	scanf("%d",&usr_level);
	if (usr_level==0)
		{devide_num=10;
		max=2;}
	else if (usr_level==1)
		{devide_num=100;
		max=devide_num/15;}	
	else if (usr_level==2)
		{devide_num=1000;
		max=devide_num/15;}	
	else if (usr_level==3)
		{devide_num=10000;
		max=devide_num/15;}	

	int inp;
	int ans=rand()%devide_num;

	printf("please guess a number between 0 and %d, you have %d chances\n",devide_num-1,max);
	do{
		count++;
		printf("your input is:");
		scanf("%d",&inp);
		if (inp>ans)
			printf("\asmaller\n");
		else if (inp<ans)
			printf("\abigger\n");
		printf("%d times left\n",max-count);
	}while (inp!=ans && count<max);
	if (count>=max)
		printf("you tried out\n");
	else  if (ans==inp)
		printf("you guessed out this number in %d steps",count);
	return 0;
}