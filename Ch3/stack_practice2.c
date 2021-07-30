#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK 10

typedef struct
{
	int key;
}element;

void push(element *stack, int *top , element item);
element pop(element *stack, int *top);
void stack_full();
void stack_empty();
void OUTPUT_STACK(element *stack, int top);

void main()
{
	element stack[MAX_STACK];
	element item;
	int i, num;
	int top = -1;
	
	printf("Numbers add into stack:\n");
	scanf("%d", &num);
	
	for (i = 1; i<=num ; i++)
	{
		printf("Insert NO.%d:\n", i);
		scanf("%d", &item.key);
		push(stack, &top, item);
	}
	OUTPUT_STACK(stack, top);
	
	printf("Numbers delete from stack:\n");
	scanf("%d", &num);
	
	for (i = 1; i<=num ; i++)
		pop(stack, &top);
		
	OUTPUT_STACK(stack, top);
}

void push(element *stack, int *top , element item)
{
	if (*top == MAX_STACK-1)
		stack_full();
	else
	{
		(*top)++;
		stack[(*top)] = item;
	}
} 

element pop(element *stack, int *top)
{
	if (*top == -1)
		stack_empty();
	else
		return stack[(*top)--];
}

void stack_full()
{
	printf("STACK FULL!");
	exit(1);
}

void stack_empty()
{
	printf("STACK_EMPTY!");
	exit(1);
}
void OUTPUT_STACK(element *stack, int top)
{
	int i;
	if (top == -1)
		stack_empty();
	else
		for (i = 0; i<=top; i++)
			printf("%d ", stack[i].key);
	printf("\n");	
}
 
