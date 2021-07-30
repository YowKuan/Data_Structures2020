#include <stdio.h>
#include <time.h>
#include "SelectionSort_prac.h"
#define MAX_SIZE 1001

void main(void)
{
   int i, n, step = 10;
   int a[MAX_SIZE];
   double duration;
   clock_t start;
   long repetitions;

   //根據n = 0, 10, …, 100, 200, …, 1000來計時
   printf("   n      repetitions      time\n");
   for (n = 0; n <= 1000; n += step)
   {
   		repetitions = 0;
   		start = clock();
   		while (clock() - start < 1000)
   		{
   			repetitions++;
   			for(i = 0; i < n; i++)
   				a[i] = n - i;
   			sort(a, n);
   		} 
   		
		duration = ((double) (clock() - start)) / CLOCKS_PER_SEC;
   		duration /= repetitions;
		printf("%4d   %14d    %f\n", n, repetitions, duration);
   		if (n == 100) step = 100;
   }
}
