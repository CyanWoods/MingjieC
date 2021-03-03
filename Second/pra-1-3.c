#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{
	int count=0;
	int ans;
	int inp;

	int t=time(NULL);
	srand(t);
	ans=(rand()%1999)-999;
	
	do{
		count++;


