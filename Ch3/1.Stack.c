#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 /*maximum stack size*/

typedef struct {
	int key;
    /* other fields */
 } element;
void push(element *stack, int *top, element item);
element pop(element *stack, int *top);
void stack_full();
void stack_empty();
void Output_stack(element *stack, int top);

void main()
{
	element stack[MAX_STACK_SIZE];
 	int top = -1;
 	int num, i;
	element item;
	
	printf("Enter the number of data items to be pushed into the stack: ");	
	scanf("%d", &num);//why這邊要用地址? 
	
	for (i = 1; i <= num; i++)
	{
		printf("\nEnter the data item No.%d: ", i);
		scanf("%d", &item.key);//先抓出一個item.key的地址, 做scanf ,將輸入的值傳入之前指定的地址 
		push(stack, &top, item);//因為會改變top, 然後stack是陣列, 陣列本身就是一個指標, 所以不能加地址符號,  
		printf("The data item %d has been added.\n", item.key);
	}

	printf("\nEnter the number of data items to be popped from the stack: ");	
	scanf("%d", &num);	
	printf("\n");

	for (i = 1; i <= num; i++)
	{
		item = pop(stack, &top);
		printf("The data item No.%d (with key value = %d) popped!\n", i, item.key);
	}	
	
	printf("The current data items in the stack include:\n");
	Output_stack(stack, top);	
}

void push(element *stack, int *top, element item)// call function = 再複製出一段記憶體做事, 如果不用指標, 改的只會是複製過後地方的值,不會影響原本的, 所以要拿到地址(*) 
{
	if (*top >= MAX_STACK_SIZE - 1)
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
	printf("Stack full!\n");
	exit(1); 
}

void stack_empty()
{
	printf("Stack empty!\n");
	exit(1); 	
}

void Output_stack(element *stack, int top)
{
	int i;

	if (top == -1)
    	stack_empty();
	else	
		for (i = 0; i <= top; i++)
			printf("%d ", stack[i].key);
}
