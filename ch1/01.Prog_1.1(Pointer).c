#include <stdio.h>
#include <stdlib.h>
void main()
{
	int *pi;
	float *pf;

 	pi =  (int)malloc (sizeof(int));
	pf =  (float)malloc (sizeof(float));
	*pi = 1024;
	*pf = 3.14;
	printf("an integer = %d, a float = %f\n", *pi, *pf);
	printf("Address an integer = %p, a float = %p\n", pi, pf);
	free(pi);
	free(pf);
}
