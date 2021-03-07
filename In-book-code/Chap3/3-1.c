#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (void)
{
    int hum;
    int comp;
    int res;
    int re;

    srand(time(NULL));

    printf("猜拳游戏开始。\n");

    do
    {
        printf("剪刀石头布：(0)剪刀 (1)石头 (2)布 \n");
        scanf("%d",&hum);
        printf("我选择出：");
        switch (hum)
        {
            case 0:printf("剪刀\n");    break;
            case 1:printf("石头\n");    break;
            case 2:printf("布\n");      break;                
        }
        
        comp=rand()%3;
        printf("电脑出：");
        switch (comp)
        {
            case 0:printf("剪刀\n");    break;
            case 1:printf("石头\n");    break;
            case 2:printf("布\n");      break;                
        }
        
        res=(hum-comp+3)%3;
        switch (res)
        {
            case 0: printf("平局\n");   break;
            case 1: printf("你赢了\n"); break;
            case 2: printf("你输了\n"); break;
        }
        printf("你还想再来一把吗？(0)no (1)yes\n");
        scanf("%d",&re);    
    } while(re==1);
    return 0;
}