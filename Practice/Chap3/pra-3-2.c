#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int human;		
int comp;		
int win_no;		
int lose_no;	
int draw_no;
int n;	
int i;

char *hd[] = {"石头", "剪刀", "布"};	

void initialize(void)
{
	win_no	= 0;		
	lose_no	= 0;		
	draw_no	= 0;		

	srand(time(NULL));

	printf("猜拳游戏开始!!\n");
}


void jyanken(void)
{
	int i;

	comp = rand() % 3;		

	do {
		printf("\n\a石头剪刀布");
		for (i = 0; i < 3; i++)
			printf(" (%d)%s", i, hd[i]);
		printf(":");
		scanf("%d", &human);		
	} while (human < 0 || human > 2);
}


void count_no(int result)
{
	switch (result) {
	 case 0: draw_no++;	 break;			
	 case 1: lose_no++;	 break;					
	 case 2: win_no++;   break;						
	}
}


void disp_result(int result)
{
	switch (result) {
	 case 0: puts("平局");	 break;	
	 case 1: puts("你输了");   break;	 
	 case 2: puts("你赢了");   break;
	}
}

int setgoal(int i)
{
	printf("要猜赢几次？\n");
	scanf("%d",&n);
	return 1;
}
int main(void)
{
	int judge;				
	initialize();				
	setgoal(i);
	do {
		jyanken();				

		printf("我出%s，你出%s。\n", hd[comp], hd[human]);

		judge = (human - comp + 3) % 3;	

		count_no(judge);				

		disp_result(judge);				

	} while (win_no < n && lose_no < 3);

	printf(win_no == n ? "\n你赢了\n" : "\n我赢了\n");

	printf("%d胜%d负%d平\n", win_no, lose_no, draw_no);

	return 0;
}
