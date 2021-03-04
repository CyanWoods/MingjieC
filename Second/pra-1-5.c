#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	srand(time(NULL));
	int a=rand()%1000;
	int b=rand()%1000;
	int c;
	if (a>b){
		c=a;
		a=b;
		b=c;
	}		// make sure a<b
	
	int max=(b-a)/15;
	int count=0;

	int inp;
	int ans=a+rand()%(b-a);
	printf("a=%d, b=%d, ans=%d,\n range=%d, max=%d\n\n",a,b,ans,b-a,max);

	printf("please guess a number between %d and %d, you have %d chances\n",a,b,max);
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




