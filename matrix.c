#include <stdio.h>

int main (void)
{
    int retry;
    do
    {    
/*输入矩阵的大小*/
        int j,k,n,m;
        printf("输入矩阵A B的行列大小 NxK KxM\n");
        do
        {
            scanf("%d",&n);
            scanf("%d",&k);
            scanf("%d",&j);
            scanf("%d",&m);
            if (j!=k)
                printf("A矩阵的列数不等于B矩阵的行数，请重新输入\n");
        }while (j!=k);
        printf("输入格式正确，开始输入矩阵的元素值。\n");

    //记录并打印矩阵A
        int count1,count2,count3;
        float a[n*k];
        float b[k*m];
        printf("请按行输入矩阵A的%d个元素\n",k*n);
        for (count1=1;count1<=n*k;count1++) 
        {
            scanf("%f",&a[count1]);
        }

        int count;
        int row;
        printf("\n矩阵A为：\n");
        for (count=1;count<=n*k;) 
            {
                for(row=0;row<k;row++)
                {   
                    printf("%.2f\t",a[count++]);
                }
                printf("\n");
            }
        printf("\n");

    //记录并打印矩阵B
        printf("请按行输入矩阵B的%d个元素\n",k*m);
        for (count2=1;count2<=m*k;count2++) 
        {
            scanf("%f",&b[count2]);
        }

        printf("\n矩阵B为：\n");
        for (count=1;count<=m*k;) 
            {
                for(row=0;row<m;row++)
                {   
                    printf("%.2f\t",b[count++]);
                }
                printf("\n");
            }
            printf("\n");

    //开始计算矩阵C
        float c[n*m];
        float sum=0;
        int p,q;
        int i;
        for (q=0;q<n;q++)
        {
            for (p=1;p<=m;p++)
            {
                sum=0;
                for (i=1;i<=k;i++)
                    sum=sum+a[i+q*k]*b[p+(i-1)*m];
                c[p+q*m]=sum;
            }
        }

    printf("矩阵c为：\n");
        for (count=1;count<=m*n;) 
            {
                for(row=0;row<m;row++)
                {   
                    printf("%.2f\t",c[count++]);
                }
                printf("\n");
            }
            printf("\n");
    printf("你想继续算吗？(0)no (1)yes");
    scanf("%d",&retry);
    }while(retry==1);
    return 0;
}