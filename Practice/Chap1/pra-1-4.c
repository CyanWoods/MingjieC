//编写一个“猜数游戏”，让目标数字是一个在3和999之间的3的倍数（例如3，6，9，……，999）。编写以下两种功能：一种是当输入的值不是3的倍数时，游戏立即结束；另一种是输入的值不是3的倍数时，不显示目标数字和输入的数值的比较结果，直接让玩家再次输入新的数值（不作为输入次数）。


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
