#include <stdio.h>
#include <stdlib.h>
#define MAX_COL 101   /* maximum number of terms +1*/   
typedef struct {
          int col;
		   int row;
		   int value;
       } term;
void fast_transpose(term a[], term b[]);

void main()
{
	term a[MAX_COL], b[MAX_COL];
	int i;
	
	// Generate a
	a[0].row = 6;
	a[0].col = 6;
	a[0].value = 8;
	a[1].row = 0;
	a[1].col = 0;
	a[1].value = 15;
	a[2].row = 0;
	a[2].col = 3;
	a[2].value = 22;
	a[3].row = 0;
	a[3].col = 5;
	a[3].value = -15;
	a[4].row = 1;
	a[4].col = 1;
	a[4].value = 11;
	a[5].row = 1;
	a[5].col = 2;
	a[5].value = 3;
	a[6].row = 2;
	a[6].col = 3;
	a[6].value = -6;
	a[7].row = 4;
	a[7].col = 0;
	a[7].value = 91;
	a[8].row = 5;
	a[8].col = 2;
	a[8].value = 28;
	printf("Output a:\n");
	for (i = 0; i <= 8; i++)
	{
		printf("(%d, %d, %d)", a[i].row, a[i].col, a[i].value);
		printf("\n");
	}
	
	fast_transpose(a, b);
	
	printf("Output b:\n");
	for (i = 0; i <= 8; i++)
	{
		printf("(%d, %d, %d)", b[i].row, b[i].col, b[i].value);
		printf("\n");
	}
}

void fast_transpose(term a[], term b[])
{
	int i, j, numbers_col[MAX_COL] = {0}, start_pos[MAX_COL];//why ={0}??
	start_pos[0] = 1;
	
	b[0].row =a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;
	
	for (i = 1; i <= a[0].value; i++)
		numbers_col[a[i].col]++;
	for (i = 1; i <= a[0].col; i++)
		start_pos[i] = start_pos[i-1] + numbers_col[i-1];
	
	for (i = 1; i <=a[0].value; i++){
		j = start_pos[a[i].col];
		start_pos[a[i].col]++;
		
		b[j].col = a[i].row;
		b[j].row = a[i].col;
		b[j].value = a[i].value; 
	}
		
		
	
}
