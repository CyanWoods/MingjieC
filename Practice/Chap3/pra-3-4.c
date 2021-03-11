#include <stdio.h>
#include <math.h>
#include <time.h> 
#include <stdlib.h>

int main(void)
{
	int i;
	int human;			
	int comp;				
	int judge;			
	int retry;				
	char *hd[] = {"石头", "剪刀", "布"};	
    int timer=0;	
    srand(time(NULL));
	printf("猜拳游戏开始!!\n");
    
	do {
		do {
			printf("\n\a石头剪刀布");
			for (i = 0; i < 3; i++)
				printf(" (%d)%s", i, hd[i]);
			printf(":");
			scanf("%d", &human);	
		} while (human < 0 || human > 2);
				
        if(timer<=0)
         {
            comp=0;
         }
         else
            comp = rand()% 3;

		printf("我出%s，你出%s。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;	
        
		switch (judge) {
		 case 0: puts("平局");	break;
		 case 1: puts("你输了");	break;
		 case 2: puts("你赢了");	break;
		}

		printf("再来一次吗？(0)否 (1)是");
		scanf("%d", &retry);
        timer=2;
	} while (retry == 1);

	return 0;
}
