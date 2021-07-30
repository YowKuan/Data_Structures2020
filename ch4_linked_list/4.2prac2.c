#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int key;
}element;

typedef struct stack* stack_pointer;
struct stack{
	element data;
	stack_pointer link;
};

void push(stack_pointer *top, element item);
void stack_print(stack_pointer top);
element pop(stack_pointer *top);


void main()
{
	stack_pointer top = NULL;
	element item;
	int i, num, data;
	printf("Enter number in stack:\n");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("Enter No.%d in stack: ", i);
		scanf("%d", &(item.key));
		push(&top, item);		
	}
	stack_print(top); 
	
	printf("Enter the numbers delete in stack:\n");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		item = pop(&top);
		printf("The data %d has been deleted\n", item.key);
	}
	stack_print(top); 

	
}

void push(stack_pointer *top, element item)
{
	stack_pointer temp;
	temp = (stack_pointer)malloc(sizeof(*temp));
	if (temp == NULL)
	{
		printf("Mem full");
		exit(1);
	 } 
	
	temp->data = item;
	temp->link = *top;
	*top = temp;

}

element pop(stack_pointer *top)
{
	stack_pointer temp = *top;
	element item;
	if (temp == NULL)
	{
		printf("list empty");
		exit(1);
	}
	
	item = temp->data;
	*top = (*top)->link;
	free(temp);
	return item;	
}


void stack_print(stack_pointer top)
{
	printf("Current stack is:\n");
	for(; top!=NULL ; top = top->link)
	{
		printf("%d ", top->data);
	}
	printf("\n");
}
