#include <stdio.h>
#include <stdlib.h>

int Factorial_Iterative(int N)
{
	int i, Fac = 1;
	
	if (N == 0)
		return 1;
	else
	{
		for (i = N; i >= 1; i--)
			Fac *= i;
		
		return Fac;
	}
} 

int Factorial_Recursive(int N)
{
	if (N == 0)
		return 1;
	else
		return N * Factorial_Recursive(N - 1);
}

void main(void)
{
	int N;
	
	printf("Enter an integer N = ");
	scanf("%d", &N);
	
	printf("By iterative algorithm: %d! = %d\n", N, Factorial_Iterative(N));
	printf("By recursive algorithm: %d! = %d\n", N, Factorial_Recursive(N));
}
