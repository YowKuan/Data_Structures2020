#include <stdio.h>
#include <stdlib.h>
float Float_Sum(float list[], int n, int* count);
float R_Float_sum(float list[] , int n, int* count);

void main(void)
{
	float F[10], float_sum;
	int n, i, count = 0;
	
	printf("Enter the numbur of real numbers to be added: ");
	scanf("%d", &n);
	printf("Enter %d real numbers:\n", n);
	for (i = 0; i < n; i++)
		scanf("%f", &F[i]);
	float_sum = Float_Sum(F, n, &count);
	printf("[Iterative] The number of steps = %d\n", count);
	for (i = 0; i < n; i++)
	{
		if (i < n - 1)
			printf("%.2f + ", F[i]);
		else
			printf("%.2f = ", F[i]);
	}
	printf("%.2f\n", float_sum);
	
	// Recursive version
	count = 0;
	float_sum = R_Float_sum(F, n, &count);
	printf("[Recursive] The number of steps = %d\n", count);
	for (i = 0; i < n; i++)
	{
		if (i < n - 1)
			printf("%.2f + ", F[i]);
		else
			printf("%.2f = ", F[i]);
	}
	printf("%.2f", float_sum);
}

float Float_Sum(float list[], int n, int *count)
{
    float tempsum = 0; (*count)++;
    int i;
    for(i = 0; i < n ; i++) 
	{
        (*count)++;   /* �p��for�j�� */
        tempsum += list[i] ; (*count)++;  /* �p����� */
    }
    (*count)++;   /* �p��for���̫�@������ */
    
	(*count)++;   /*�p��^��*/  
	return tempsum;
}

float R_Float_sum(float list[] , int n, int *count)
{
	(*count)++; /* �p��if������P�_ */
    if (n) 
	{
       (*count)++; /* �p��return��R_Float_sum�Q�I�s������*/
       return (R_Float_sum(list, n-1, &(*count)) + list[n-1]);
    }
    
	(*count)++;
    return 0.0;
}
