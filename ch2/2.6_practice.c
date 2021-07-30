#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100

typedef struct{
	int expon;
	float coeff;
}item;
item a[MaxSize];
int avail = 0;

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd);
void attach(float coefficient, int exponent);
int compare(int expo_a, int expo_b);

void main(){
	int i, startd, finishd;
	
	a[0].coeff = 3.5;
	a[0].expon = 8;
	a[1].coeff = 4.5;
	a[1].expon = 2;
	a[2].coeff = 7;
	a[2].expon = 1; 
	a[3].coeff = 28;
	a[3].expon = 0;
	
	a[4].coeff = -1;
	a[4].expon = 8;
	a[5].coeff = 19;
	a[5].expon = 6;
	a[6].coeff = 3;
	a[6].expon = 2;
	
	avail = 7;

	padd(0, 3, 4, 6, &startd, &finishd);
	printf("%d, %d\n",startd, finishd);
	for (i=startd; i<=finishd; i++){
		printf("(%.1f, %d)\n", a[i].coeff, a[i].expon);
	}
}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd){
	float coefficient;
	*startd = avail; 
	while(starta <= finisha && startb <= finishb)//為啥這邊不用括號? 
		switch(compare(a[starta].expon, a[startb].expon))
		{
			case -1:
				attach(a[startb].coeff, a[startb].expon);
				startb++;
				printf("Case-1\n");
			break;
			case 0:
				coefficient = a[starta].coeff + a[startb].coeff;
				if (coefficient)
				{				
					attach(coefficient, a[startb].expon);
					starta++;
					startb++;
				} 
				printf("Case 0\n");
			break;
				 
			case 1:
				attach(a[starta].coeff, a[starta].expon);
				starta++;
				printf("Case 1\n");
			break;	
		}
		for(; starta <= finisha; starta++)
			attach(a[starta].coeff, a[starta].expon);
		for(; startb<= finishb; startb++)
			attach(a[startb].coeff, a[startb].expon);
		*finishd = avail-1;	

} 

void attach(float coefficient, int exponent){
	if (avail > MaxSize){
		printf("Exceed largest storage!!");
		exit(1);
	}
	a[avail].coeff = coefficient;
	a[avail].expon = exponent;
	avail++; 
}

int compare(int expo_a, int expo_b){
	if (expo_a > expo_b)
		return 1;
	else if (expo_a == expo_b)
		return 0;
	else
		return -1;
}




