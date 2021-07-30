#include <stdio.h>
#include <stdlib.h>
void print1(int *ptr, int rows);
//void print1(int ptr[], int rows);
void main()
{
	int one[] = {0, 1, 2, 3, 4};

	print1(one, 6);
	printf("%d", one+2);
	
}

void print1(int *ptr, int rows) /* 函數並未配置新記憶體,僅將陣列的位址傳入*/
//void print1(int ptr[], int rows)
{
     /* print out a one-dimensional array using a pointer */
     int i;
     
     printf(" Address Contents\n");
     for (i = 0; i < rows; i++)
     	printf("%8u%5d\n", ptr + i, *(ptr + i));
     	//printf("%8u%5d\n", &ptr[i], ptr[i]);
     printf("\n");                  /* ptr+i  = &ptr[i]*/
}

