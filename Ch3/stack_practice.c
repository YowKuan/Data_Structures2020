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
void Output(element *stack, int top);

void main()
{
	element stack[MAX_STACK_SIZE];
	int top = -1;
	int i, num;
	element item;
	
	printf("Enter how many numbers you want to put into stack:");
	scanf("%d", &num);
	
	for (i=1; i<=num; i++){
		printf("\nInsert the number you want to add No.%d:", i);
		scanf("%d", &item.key);//why ¦a§} 
		push(stack, &top, item);// why address?
		printf("\n The number %d has been added", item.key);	
	}

	printf("\nEnter how many numbers you want to delete from stack:", i);
	scanf("%d", &num);
	for (i=1; i<=num; i++)
	{
		item = pop(stack, &top);
		printf("The data item No.%d (with key value = %d) popped!\n", i, item.key);
	}	
	
	printf("The final result is:\n");
	Output(stack, top);
	
}  

void push(element *stack, int *top, element item)
{
	if (*top >= MAX_STACK_SIZE -1)
		stack_full();
	else{
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
	printf("Stack full!\n");
	exit(1);	
}

void stack_empty()
{
	printf("Stack empty!\n");
	exit(1);	
}

void Output(element *stack, int top)
{
	int i;
	if (top == -1)
		stack_empty();
	
	else{
	for (i = 0 ; i <= top; i++)
		printf("%d ", stack[i].key);
		
	}
	
	
}






