#include <stdio.h>

int main(void)
{
    printf("关于字符串常量与字符常量\n");
   
    putchar('"');
    printf("双引号\n");
    printf("用双引号括起来的\"ABC\"是字符串常量。\n");

    putchar('\'');
    printf("单引号\n");
    printf("用单引号括起来的'ABC'是字符串常量。\n");//同时注意这里的单引号双引号的引出方法；
    return 0;
}
