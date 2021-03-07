#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main (void)
{
    int human;
    int computer;
    int retry;
    int compare;

    printf("猜拳游戏开始。\n");
    
    do{
        do 
        {
            printf("剪刀石头布：(0)剪刀 (1)石头 (2)布 \n");
            scanf("%d",&human);
        }while(human<0||human>2);

        printf("我出的是：");
        switch(human)
        {
            case 0: printf("剪刀");    break;
            case 1: printf("石头");    break;
            case 2: printf("布");      break;
        }
        printf("；");
        
        printf("电脑出的是：");
        computer=rand()%3;
        switch(computer)
        {
            case 0: printf("剪刀");    break;
            case 1: printf("石头");    break;
            case 2: printf("布");      break;
        }
        printf("。\n");

        
        printf("结果是：");
        compare=(human-computer+3)%3;
        switch(compare)
        {
            case 0: printf("平局");  break;
            case 1: printf("你赢了");   break;
            case 2: printf("你输了");    break;
        }
        printf("。\n");
        
        printf("重来？(0)no (1)yes");
        scanf("%d",&retry);
    }while(retry==1);
    return 0;
}