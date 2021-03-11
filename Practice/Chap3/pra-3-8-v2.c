#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	int human;			
	int comp1,comp2,comp3;					
	int judge1,judge2,judge3,judge;			
	int retry;				
	char *hd[] = {"石头", "剪刀", "布"};	
    int cnt=0;	
    int c=1;
	int want;

    srand(time(NULL));
	printf("你想赢几次？");
	scanf("%d",&want);

	printf("猜拳游戏开始!!\n");

	do {
 		do 
		{
			printf("\n\a石头剪刀布");
			for (i = 0; i < 3; i++)
				printf(" (%d)%s", i, hd[i]);
			printf(":");
			scanf("%d", &human);	
		} while (human < 0 || human > 2);
		comp1 = rand()% 3;	
		comp2 = rand()% 3;	
        comp3 = rand()% 3;	
		
        printf("1出%s，2出%s，3出%s，你出%s。\n", hd[comp1],hd[comp2],hd[comp3], hd[human]);
  
       	judge1 = (human - comp1 + 3) % 3;	
        judge2 = (human - comp2 + 3) % 3;	
        judge3 = (human - comp3 + 3) % 3;

        if (judge1==1&&judge2==1&&judge3==1)
            judge=1;
        else if (judge1==2&&judge2==2&&judge3==2)
            judge=2;   
        else if (judge1==0&&judge2==0&&judge3==0)
            judge=0;
        else judge=3;
		switch (judge) {
		 case 0: puts("平局");	break;
		 case 1: puts("你输了");	break;
		 case 2: puts("你赢了");cnt++;	break;
         default: puts("无结果");	break;
		}
        printf("当前是第%d次。\n你赢了%d次。\n",c,cnt);
		c++;

	} while (cnt<want);

	return 0;
}
