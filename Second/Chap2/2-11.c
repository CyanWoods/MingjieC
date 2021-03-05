#include <stdio.h>

int main(void)
{
    int a, b;
    int num;

    printf("rows you want to show:");
    scanf("%d",&num);
    for (a=1;a<=num;a++)
    {
        for (b=1;b<a;b++)
            putchar(' ');
    printf("%d\n",a%10);
    }
    return 0;
}