#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 /* maximum stack size */
#define MAX_EXPR_SIZE 100   /* max size of expression */

typedef enum {
		plus, minus, times, divide, mod, eos, operand
	} precedence;
	
precedence get_token(char *symbol, char *expr, int *n);
void push(int *stack, int *top, int item);
int pop(int *stack, int *top);
void stack_full();
void stack_empty();
void Output_stack(int *stack, int top);

void main()
{
	int stack[MAX_STACK_SIZE];   
	char expr[MAX_EXPR_SIZE];   

	printf("Enter a postfix expression:\n");
	scanf("%s", expr);
	printf("The evaluation result = %d", eval(expr, stack));
}

void push(int *stack, int *top, int item)
{
	if (*top >= MAX_STACK_SIZE - 1)
    	stack_full();
	else
	{
		(*top)++;
		stack[(*top)] = item;
	}
}

int pop(int *stack, int *top)
{
	if (*top == -1)
    	stack_empty();
    else
    	return stack[(*top)--];
}

int eval(char *expr, int *stack)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	int top = -1;
	
	token = get_token(&symbol, expr, &n);
	while (token != eos)
	{
		if (token == operand)
		{
			push(stack, &top, symbol - '0');
			Output_stack(stack, top);
		}
		else
		{
			op2 = pop(stack, &top);
			Output_stack(stack, top);
			op1 = pop(stack, &top);
			if (top != -1)
				Output_stack(stack, top);
			else
				printf("\n \n");
			switch (token)
			{
				case plus: push(stack, &top, op1 + op2);
				break;
				case minus: push(stack, &top, op1 - op2);
				break;
				case times: push (stack, &top, op1 * op2);
				break;
				case divide: push(stack, &top, op1 / op2);
				break;
				case mod: push(stack, &top, op1 % op2);
				break;
			} 
			Output_stack(stack, top);
		}
		token = get_token(&symbol, expr, &n);
	}
	
	return pop(stack, &top);	
}

precedence get_token(char *symbol, char *expr, int *n)
{    
	*symbol = expr[(*n)++];
	switch (*symbol)  
	{
		case '+':   return plus;
		break;
		case '-':   return minus;
		break;
		case '/':   return divide;
		break;
		case '*':   return times;
		break;
		case '%':   return mod;
		break;
		case '\0':	return eos;//ªÅ¦r¦ê 
		break;
		default:	return operand;
		break;
	}
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

void Output_stack(int *stack, int top)
{
	int i;

	if (top == -1)
    	stack_empty();
	else
	{	
		printf("\n"); 
		for (i = 0; i <= top; i++)
			printf("%d  ", stack[i]);
		printf("\n"); 
	} 
}
