#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 10

typedef struct {
       float coef;
       int expon;
} polynomial;
polynomial terms[MAX_TERMS];
int avail = 0;
void padd(int start_a, int end_a, int start_b, int end_b, int *start_d, int *end_d);
void attach(float coefficient, int exponent);
int COMPARE(int expon_a, int expon_b);

void main()
{
	int startd, finishd;
	int i;
	// Fill the data for 1-st poly
	terms[0].coef = 3;
	terms[0].expon = 3;
	terms[1].coef = 5;
	terms[1].expon = 2;
	terms[2].coef = 5;
	terms[2].expon = 0;	
	printf("Poly1:");
	for (i = 0; i <= 2; i++)
		printf("(%.0f, %d) ", terms[i].coef, terms[i].expon);
	printf("\n");
	// Fill the data for 2-nd poly
	terms[3].coef = -5;
	terms[3].expon = 2;
	terms[4].coef = 7;
	terms[4].expon = 1;
	terms[5].coef = 3;
	terms[5].expon = 0;	
	printf("Poly2:");
	for (i = 3; i <= 5; i++)
		printf("(%.0f, %d) ", terms[i].coef, terms[i].expon);
	printf("\n");
	avail = 6; 
	padd(0, 2, 3, 5, &startd, &finishd);
	printf("After adding poly1 and poly2:\n");
	printf("(startd, finishd) = (%d, %d)\n", startd, finishd);
	for (i = startd; i <= finishd; i++)
		printf("(%.0f, %d) ", terms[i].coef, terms[i].expon);
}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{
	/*add A(x) and B(x) to obtain D(x) */
    float coefficient;
    *startd = avail;
    printf("%d\n", *startd);
    
	while ((starta <= finisha) && (startb <= finishb))
    	switch(COMPARE(terms[starta].expon, terms[startb].expon)) 
		{
        	case -1: /* a expon < b expon */
                    attach(terms[startb].coef, terms[startb].expon);
                    startb++;
            break;
            case 0: /* equal expontents */
                   coefficient = terms[starta].coef + terms[startb].coef; 
                   if(coefficient) 
				      attach(coefficient, terms[starta].expon);
                   starta++;
                   startb++;
            break;
			case 1: /* a expon > b expon */
              	   attach(terms[starta].coef, terms[starta].expon);
                   starta++;
            break;
		}
		/* add in remaining terms of A(x) */
		for (; starta <= finisha; starta++)
    		attach(terms[starta].coef, terms[starta].expon);
		/* add in remaining terms of B(x) */
		for (; startb <= finishb; startb++)
    		attach(terms[startb].coef, terms[startb].expon);
		*finishd = avail-1;
}

void attach(float coefficient, int exponent)
{
	/* add a new term to the polynomial */
    if (avail > MAX_TERMS) 
	{
    	fprintf(stderr, "Too many terms in the polynomial\n");
        exit(1);
    }
    terms[avail].coef = coefficient;
    terms[avail].expon = exponent;
    avail++;
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
