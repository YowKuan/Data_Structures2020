#include <stdlib.h>
#include <stdio.h>
#define MAX_STACK 100
#define MAX_EXPR 100

typedef enum{
	plus, minus, times, divide, mod, eos, operand
}precedence;

void push(int *stack, int *top, int item);
int pop(int *stack, int *top);
void stack_full();
void stack_empty();
precedence get_token(char *symbol, char *expr, int *n);
void OUTPUT_STACK(int *stack, int top);


void main()
{
	int expr[MAX_EXPR];
	int stack[MAX_STACK];
	printf("Please type postfix input:\n");
	scanf("%s", expr);
	printf("The result is: %d", eval(expr, stack));
	
}


int eval(int *expr, int *stack)
{
	precedence token;
	int op1, op2;
	char symbol;
	int n = 0;
	int top = -1;
	token = get_token(&symbol, expr, &n);
	while (token != eos)
	{
		if (token == operand)
		{
			push(stack, &top, symbol -'0');//ª`·N!! 
			OUTPUT_STACK(stack, top);	
		}
		else 
		{
			op2 = pop(stack, &top);
			OUTPUT_STACK(stack, top);
			op1 = pop(stack, &top);
			if (top != -1)
				OUTPUT_STACK(stack, top);
			else
				printf("\n \n");
			switch(token)
			{
				case plus:
					push(stack, &top, op1 + op2);
					break;
				case minus:
					push(stack, &top, op1 - op2);
					break;
				case times:
					push(stack, &top, op1 *op2);
					break;
				case divide:
					push(stack, &top, op1 / op2);
					break;
				case mod:
					push(stack, &top, op1 % op2);
					break;
			}
			OUTPUT_STACK(stack, top);			
		}
	token = get_token(&symbol, expr, &n);
	}
	pop(stack, &top);	
}


precedence get_token(char *symbol, char *expr, int *n)
{
	*symbol = expr[(*n)++];
	switch(*symbol)
	{
		case '+':	return plus;
		break;
		case '-':	return minus;
		break;
		case '*':	return times;
		break;
		case '/':	return divide;
		break;
		case '%':	return mod;
		break;
		case '\0':	return eos;
		break;
		default:	return operand;
		break;
	}
	
}

void push(int *stack, int *top, int item)
{
	if (*top == MAX_STACK -1)
		stack_full();
	else
		(*top)++;
		stack[(*top)] = item;
}

int pop(int *stack, int *top)
{
	if (*top == -1)
		stack_empty();
	else
		return stack[(*top)--];
}

void stack_full()
{
	printf("Stack full!!!\n");
	exit(1);
} 

void stack_empty()
{
	printf("Stack empty!!!\n");
	exit(1);
} 

void OUTPUT_STACK(int *stack, int top)
{
	int i;
	if (top == -1)
		stack_empty();
	else
	{
		for (i = 0; i <= top; i++)
			printf("%d ", stack[i]);	
		printf("\n \n");
		
	}
		
}










 
