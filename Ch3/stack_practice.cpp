#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef struct{
	int key;
}element ;
void push(element *stack, int *top, element item);
element pop(element *stack, int *top);
void stack_full();
void stack_empty();
void Output(element *stack, int *top);



void main()
{
	element stack[MAX_STACK_SIZE];
	int top = -1;
	int i, num;
	element item;
	
	printf("Enter how many numbers you want to put into stack:/n");
	scanf("%d", &num);
	
	for (i=0; i<=num; i++)
		printf("Insert the number you want to add:\n");
		scanf("%d", &item.key);//why ¦a§} 
		push(stack, &top, item);// why address?
	
	printf("Enter how many numbers you want to delete from stack:/n");
	scanf("%d", &num);
	
	for (i=0; i<=num; i++)
		pop(stack, &top);
	
	printf("The final result is:\n");
	Output(stack, top);
	
}  

void push(element *stack, int *top, element item)
{
	if (*top >= MAX_STACK_SIZE -1)
		stack_full();
	else
		*top++;
		stack[(*top)] = item;
				 
}

void pop(element *stack, int *top)
{
	if (*top == -1)
		stack_empty();
	else
		*top--;
}

void stack_full()
{
	printf("Stack full!\n");
	exit(1);	
}

void stack_empty()
{
	printf("Stack empty!\n");
	exit(1);	
}

void Output(element *stack, int *top)
{
	if (*top == -1)
		stack_empty();
	else
		for (i = 0 ; i <= *top; i++)
		printf("%d", *stack[i].key);
	
}






