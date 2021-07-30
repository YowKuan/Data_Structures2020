#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3
int add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], 
        int rows, int cols);
         
void main(void)
{
	int a[3][MAX_SIZE], b[3][MAX_SIZE], c[3][MAX_SIZE];
	int i, j, count;
	 
	printf("Enter the first matrix:\n");
	for (i = 0; i < 3; i++)
	{
		printf("The %d row: ", i + 1);
		for (j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	}

	printf("Enter the second matrix:\n");
	for (i = 0; i < 3; i++)
	{
		printf("The %d row: ", i + 1);
		for (j = 0; j < 3; j++)
			scanf("%d", &b[i][j]);
	}
	
	count = add(a, b, c, 3, 3);
	printf("\n");
	
	printf("The result:\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%d ", c[i][j]);
		printf("\n");
	}
	
	printf("It takes %d steps.\n", count);
}

int add(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], 
        int rows, int cols)
{
	int i, j;
    int count = 0;
	
	for (i = 0 ; i < rows ; i++) 
	{
        count++;  /* 計算i迴圈 */
        for (j = 0 ; j < cols ; j++) 
		{
            count++;  /* 計算j迴圈 */
            c[i][j] = a[i][j] + b[i][j] ;
            count++ ; /* 計算指派*/
        }
        count++ ; /* 計算最後一次的j迴圈 */ 
    }
    count++ ;  /* 計算最後一次的i迴圈 */ 

	return count;
}
