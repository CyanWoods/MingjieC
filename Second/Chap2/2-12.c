#include <stdio.h>

int main(void)
{
    int a, b;
    int num;

    printf("rows you want to show:");
    scanf("%d",&num);
    for (a=1;a<=num;a++)
        printf("%*d\n",a,a%10);
    
    return 0;
}