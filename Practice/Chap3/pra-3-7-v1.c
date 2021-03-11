#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int i;
	int human;			
	int comp;				
	int judge;			
	int retry;				
	char *hd[] = {"石头", "剪刀", "布"};	
    int cnt=0;	
    int c=1;

    srand(time(NULL));

	printf("猜拳游戏开始!!\n");

	do {

        human = rand()% 3;
		comp = rand()% 3;	

		printf("我出%s，你出%s。\n", hd[comp], hd[human]);
  
       	judge = (human - comp + 3) % 3;	


		switch (judge) {
		 case 0: puts("平局");	break;
		 case 1: puts("你输了");	break;
		 case 2: puts("你赢了");cnt++;	break;
		}
        printf("当前是第%d次。\n你赢了%d次。\n",c,cnt);
		c++;
		printf("再来一次吗？(0)否 (1)是");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
