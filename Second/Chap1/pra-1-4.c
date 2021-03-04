#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	int r;
	int ans;
	int inp;
	int count;
	int max=20;
	int remain;

	srand(time(NULL));
	r=rand();
	ans=((r%333)+1)*3;
	printf("ans=%d\n",ans);

	count=0;
	inp=0;
	printf("请输入一个3-999之间且能被3整除的数。\n");
	while (ans!=inp&&count<max){
		printf("please input the number you like:");
		scanf("%d",&inp);
		if (inp%3==0){
			count++;
			printf("%d times left\n",max-count);
			if (inp>ans)
				printf("\asmaller\n");
			else if (inp<ans)
				printf("\abigger\n");
			}
		else{break;}
		}
	if (inp==ans)
		printf("congratulatin!, you guessed out this number in %d steps\n",count);
	else if (count>=max)
		printf("sorry, but you tried out the max number of tries.\n");
	else
		printf("you inputted a munber could not be devided by 3\n");
	return 0 ;
}
