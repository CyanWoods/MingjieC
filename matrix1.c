#include <stdio.h>

int main (void)
{
    int retry;
    int i,cnt;
    do
    {    
/*输入矩阵的大小*/
        int j,k,n,m;
        printf("输入矩阵A B的行列大小 NxK KxM\n");
        do{
            scanf("%d %d %d %d",&n,&k,&j,&m);
            if (j!=k)
                printf("A矩阵的列数不等于B矩阵的行数，请重新输入\n");
        }while (j!=k);
        printf("输入格式正确，开始输入矩阵的元素值。\n");

//记录并打印矩阵A
        float a[n][k];
        for (i=1;i<=n;i++)
        {
            for (cnt=1;cnt<=k;cnt++)
                scanf ("%f",&a[i][cnt]);
        }

        for (i=1;i<=n;i++)
        {
            for (cnt=1;cnt<=k;cnt++)
                printf("\t%.2f",a[i][cnt]);
            printf("\n");
        }

//记录并打印矩阵B
        float b[k][m];
        for (i=1;i<=k;i++)
        {
            for (cnt=1;cnt<=m;cnt++)
                scanf ("%f",&a[i][cnt]);
        }

        for (i=1;i<=k;i++)
        {
            for (cnt=1;cnt<=m;cnt++)
                printf("\t%.2f",a[i][cnt]);
            printf("\n");
        }

//计算矩阵并打印
        float c[n][m];
        int p,q;
        float sum=0;
        for (p=1;p<=n;p++)
        {
            for(q=1;q<=m;q++)
            {
                for(i=1;i<=k;i++)
                sum=sum+a[p][i]*b[i][q];
            }
        }

        for (i=1;i<=n;i++)
        {
            for (cnt=1;cnt<=m;cnt++)
                printf("\t%.2f",c[i][cnt]);
            printf("\n");
        }
        printf("你想继续算吗？(0)no (1)yes");
        scanf("%d",&retry);
    }while(retry==1);
    return 0;
}