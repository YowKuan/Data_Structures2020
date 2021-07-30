#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 101
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))  // Macro definition
//#define SWAP(x, y, t) (t = x, x = y, y = t) 
void sort(int [], int);
void swap(int *, int *);

void main(void)
{
	int i, n;
	int list[MAX_SIZE];
	printf("Enter the number of numbers to generate: ");
   	scanf("%d", &n);

	if((n < 1) || (n > MAX_SIZE))
	{
		fprintf(stderr, "Improper value of n\n");
		exit(EXIT_FAILURE);  /* EXIT_FAILURE = 1*/
	}

	for (i = 0; i < n ; i++) 
	{  /*隨機產生數值*/
    	list[i] = rand() % 1000;
		printf("%d ", list[i]);
    }

	sort (list, n);
	
	printf("\nSorted array:\n");
    for(i = 0; i < n; i++)  /*印出已排好序的數值*/
		printf("%d ", list[i]);
    printf("\n");
}

void sort(int list[], int n)
{
   int i, j, min, temp;
   
   for(i = 0; i < n; i++)
   {
      min = i;
      
	  for(j = i + 1; j < n; j++) 
      	if(list[j] < list[min])
        	min = j;
      SWAP(list[i], list[min], temp);
      //swap(&list[i], &list[min]);
 
   }
}
// call by reference
void swap(int *x, int *y)                                                        
{                                              
    int temp = *x;
	*x = *y;
	*y = temp;                                        
} 
