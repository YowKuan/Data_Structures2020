#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
	float coeff;
	int expon;
}polynomial ;

polynomial terms[MAX];
int avail = 0;
void padd(int start_a, int end_a, int start_b, int end_b, int *start_d, int *end_d);
void add(float coefficient, int exponent);
int COMPARE(int a, int b);

void main(){
	int startd, finishd;
	int i ;
	terms[0].coeff = 3;
	terms[0].expon = 4;
	terms[1].coeff = 2;
	terms[1].expon = 3;
	terms[2].coeff = 6;
	terms[2].expon = 2;
	
	terms[3].coeff=1;
	terms[3].expon=6;
	terms[4].coeff=8;
	terms[4].expon=4;
	terms[5].coeff=2;
	terms[5].expon=2;
	terms[6].coeff=3;
	terms[6].expon=1;
	printf("Poly1");
	for (i = 0; i <= 2; i++)
		printf("(%.0f, %d)", terms[i].coeff, terms[i].expon ); //為啥不能加括號 
		printf("\n");
	printf("Poly2");
		
	for (i = 3; i<=6; i++)
		printf("(%.0f, %d)", terms[i].coeff, terms[i].expon);
		printf("\n");	
	avail=7;
	padd(0, 2, 3, 6, &startd, &finishd );
	printf("The result is:\n");
	printf("%d, %d", startd, finishd);
	for (i = startd; i <=finishd; i++)
		printf("(%.0f, %d)", terms[i].coeff, terms[i].expon);
	
	
}
void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{
	float coefficient;
	*startd = avail;
		printf("%d\n", *startd);	
	while ((starta < finisha) && (startb < finishb))
		switch(COMPARE(terms[starta].expon, terms[startb].expon))
		{
			case 1:
				add(terms[starta].coeff, terms[starta].expon);
				starta++;
				printf("yyyyy");
			break;	
			case 0:
				coefficient = terms[starta].coeff+ terms[startb].coeff;
				if (coefficient)
					add(coefficient, terms[starta].expon);
					printf("HEYYY");
				starta++ ;
				startb++ ;
			break;
				
			case -1:
				add(terms[startb].coeff, terms[startb].expon);
				startb++;
				printf("HIII");
			break;
			}
			for (; starta <= finisha; starta++)
				add(terms[starta].coeff, terms[starta].expon);
				starta++;
			for (; startb <= finishb; startb++)
				add(terms[startb].coeff, terms[startb].expon);
				startb++;
			*finishd = avail-1;
}

int COMPARE(int expon_a, int expon_b)
{
	if (expon_a < expon_b)
		return -1;
	else if (expon_a == expon_b)
		return 0;
	else
		return 1;
}

void add(float coefficient, int exponent)
{
	terms[avail].coeff = coefficient;
	terms[avail].expon = exponent;
	avail++;
}


