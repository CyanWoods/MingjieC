#include<time.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a,b,c;
	int inp;
	clock_t start,end;
	double req_time;

	srand(time(NULL));

	a=100+rand()%900;
	b=100+rand()%900;
	c=100+rand()%900;

	printf("What's the result of %d+%d+%d?",a,b,c);

	start=clock();

	while(1){
		scanf("%d",&inp);
		if(inp==a+b+c)
			break;
		printf("pls re-calculate the result.");
	}
	
	end=clock();

	req_time=(double)(end-start)/CLOCKS_PER_SEC;
	printf("%.1f %.1f",(double)start,(double)(end));
	printf("you used %.1fsecond",req_time);

	if(req_time>30)
		printf("you spent too much time");
	else if(req_time>17)
		printf("not bad");
	else
		printf("pretty well");
	
	return 0;
}
