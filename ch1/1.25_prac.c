#include <stdio.h>
#include <time.h>
#include "SelectionSort_prac.h"
#define MAX_SIZE 1001

void main()
{
	int i, n, j,  step = 10;
	clock_t start;
	long rep;
	int list[MAX_SIZE];
	double duration;
	
	printf("n    rep       time\n");
	for (i = 10; i <= 1000; i+=step)
	{
		rep = 0;
		start = clock();
		while (clock()- start <=1000)
		{
			rep++;
			for (j = 1; j <= i; j++)
				list[j] = i - j;
			sort(list, i);	
		}
		duration = ((double) clock()-start)/ CLOCKS_PER_SEC;
		duration/=rep;
		printf("%4d %7d %f\n", i, rep, duration);
		if (i==100)
			step = 100;
	}
}
