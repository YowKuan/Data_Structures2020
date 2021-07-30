#include <stdio.h>
#include <time.h>
#include "SelectionSort.h"
#define MAX_SIZE 1001

void main(void)
{
   int i, n, step = 10;
   int a[MAX_SIZE];
   double duration;
   clock_t start;

   //根據n = 0, 10, …, 100, 200, …, 1000來計時
   printf("   n      time\n");
   for (n = 0; n <= 1000; n += step)
   {
   		for(i = 0; i < n; i++)
   			a[i] = n - i;
   		/*	
   		printf("Before sorting:\n");
   		for(i = 0; i < n; i++)
   			printf("%d ", a[i]);
		*/ 
		start = clock();
   		sort(a, n);
		/*
   		printf("\nAfter sorting:\n");
   		for(i = 0; i < n; i++)
   			printf("%d ", a[i]);
	    printf("\n");	
		*/
   		duration = ((double) (clock() - start)) / CLOCKS_PER_SEC;
   		printf("%4d      %f\n", n, duration);
   		if (n == 100) step = 100;
   }
}
