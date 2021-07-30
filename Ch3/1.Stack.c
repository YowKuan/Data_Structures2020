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
	scanf("%d", &num);//why�o��n�Φa�}? 
	
	for (i = 1; i <= num; i++)
	{
		printf("\nEnter the data item No.%d: ", i);
		scanf("%d", &item.key);//����X�@��item.key���a�}, ��scanf ,�N��J���ȶǤJ���e���w���a�} 
		push(stack, &top, item);//�]���|����top, �M��stack�O�}�C, �}�C�����N�O�@�ӫ���, �ҥH����[�a�}�Ÿ�,  
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

void push(element *stack, int *top, element item)// call function = �A�ƻs�X�@�q�O���鰵��, �p�G���Ϋ���, �諸�u�|�O�ƻs�L��a�誺��,���|�v�T�쥻��, �ҥH�n����a�}(*) 
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
