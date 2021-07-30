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
element pop(stack_pointer *top);
void liststack(stack_pointer top);

void main()
{
	stack_pointer top = NULL;
	int num, i;
	element item;
	
	printf("Enter the number add into stack:");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("Enter data number %d", i);
		scanf("%d", &item.key);
		push(&top, item);
		printf("The data %d has been added\n", item.key);
	}

	liststack(top);
	
	printf("Enter the number desire to delete: \n");
	scanf("%d", &num);
	
	for (i = 1; i <=num; i++)
	{
		item = pop(&top);
		printf("The data number No.%d, with value %d has been popped\n", i, item.key);
	 } 
	liststack(top);
}

void push(stack_pointer *top, element item)
{
	stack_pointer temp = (stack_pointer) malloc(sizeof(temp));
	if(temp == NULL)
	{
		printf("Memory full");
		exit(1);
	}
	else
	{
		temp->data = item;
		temp->link = *top;
		*top = temp;
	}
}

element pop(stack_pointer *top)
{
	stack_pointer temp = *top;
	element item;
	if (temp == NULL)
	{
		printf("The stack is empty");
		exit(1);
	}
	item = temp->data;
	*top = temp->link;
	free(temp);
	
	return item;
}

void liststack(stack_pointer top)
{
	printf("The current stack is: ");
	for(top; top!=NULL; top = top->link)
		printf("%d ", (top->data).key);
	printf("\n");
}

