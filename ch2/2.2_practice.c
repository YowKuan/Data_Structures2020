#include <stdlib.h>
#include <stdio.h>

void print1(int *ptr, int rows);

void main()
{
	int a[] = {4, 5, 8, 9, 10, 17, 20, 80, 90};
	
	print1(a, 8);
}

void print1(int *ptr, int rows){
	int i;
	for(i = 0; i <= rows; i++){
		printf("%d %d\n", ptr+i, *(ptr+i));
	}
}
