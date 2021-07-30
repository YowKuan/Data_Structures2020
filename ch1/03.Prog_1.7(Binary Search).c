#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_SIZE 101
#define COMPARE(x, y) ((x < y)? -1: ((x == y)? 0:1))
void sort(int [], int);
void swap(int *, int *);
int binarysearch(int [], int, int, int);
int binarysearch_recursive(int [], int, int, int);
int compare (int, int);

void main(void)
{
	int i, n;
	int list[MAX_SIZE];
	int searchnum, found;
	
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

	sort(list, n);
	
	printf("\nSorted array:\n");
    for(i = 0; i < n; i++)  /*印出已排好序的數值*/
		printf("%d ", list[i]);
    printf("\n");

	printf("Enter the number you want to search: ");
	scanf("%d", &searchnum);
	if ((found = binarysearch(list, searchnum, 0, n - 1)) == -1)
	//if ((found = binarysearch_recursive(list, searchnum, 0, n - 1)) == -1)
		printf("%d cannot be found", searchnum);
	else
		printf("%d can be found in the position: %d\n", searchnum, found);
}

int binarysearch(int list[], int searchnum, int left, int right)
{     
	int middle;
	
    while (left <= right)
    {
		middle = (left + right) / 2;
		// switch(compare(list[middle], searchnum)) 
		switch(COMPARE(list[middle], searchnum)) 
		{
	        case -1: left = middle + 1;
            break;
	        case 0: return middle;
	        break;
	        case 1: right = middle - 1;
	        break;
	 	}
    } 
          
	return -1; 
}

int binarysearch_recursive(int list[], int searchnum, int left, int right)
{     
	int middle;
	
    if (left <= right)
    {
		middle = (left + right) / 2;
        switch(compare(list[middle], searchnum)) 
		{
	  		case -1: return binarysearch_recursive(list, searchnum, middle + 1, right);
			break;
            case 0: return middle;
            break;
	  		case 1: return binarysearch_recursive(list, searchnum, left, middle - 1);
	    }
    } 
         
	return -1; 
}

int compare(int x, int y)
{        
    if(x < y)
		return -1;
	else if(x == y)
		return 0;
	else return 1;
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
      swap(&list[i], &list[min]);
   }
}
// call by reference
void swap(int *x, int *y)                                                        
{                                              
    int temp = *x;
	*x = *y;
	*y = temp;                                        
}
