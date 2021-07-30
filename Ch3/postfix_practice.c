#include <stdlib.h>
#include <stdio.h>
#define MAX_STACK 100
#define MAX_OPER 100

typedef enum{
	plus, minus, times, divide, mod, eos, operand
}precedence;

precedence get_token(char *symbol, char *expr, int *n);
void push(int *stack, int *top, int item);
int pop(int *stack, int *top);
void stack_full();
void stack_empty();
void OUTPUT_STACK(int *stack, int top); 
 
void main()
{
	int stack[MAX_STACK];
	char expr[MAX_OPER];
	printf("Enter the postfix expression:\n");
	scanf("%s", expr);
	printf("The result is:%d\n", eval(expr, stack));
}

int eval(char *expr, int *stack)
{
	precedence token;
	char symbol;
	int n = 0;
	int top = -1;
	int op1, op2;
	token = get_token(&symbol, expr, &n);
	while (token != eos)
	{
		if (token == operand)
		{
			push(stack, &top, symbol -'0');//why!!!!!?
			OUTPUT_STACK(stack, top);
		}
		else
		{
			op2 = pop(stack, &top);
			OUTPUT_STACK(stack, top);
			op1 = pop(stack, &top);
			if (top != -1)//這裡沒符號 
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
					push(stack, &top, op1 * op2);
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
	*symbol = expr[(*n)++];//有點問題 
	switch(*symbol)
	{
		case '+':	return plus;
		break;
		case '-':	return minus;
		break;
		case '*': 	return times;
		break;
		case '/': 	return divide;
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
	if (*top >= MAX_STACK -1)
		stack_full();
	else
		(*top)++;
		stack[(*top)] = item;	
}

int pop(int *stack, int *top)
{
	if ((*top) == -1)
		stack_empty();
	else
		return stack[(*top)--];//有點疑問!!不能分成兩行寫嗎? 應該不行! 
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

void OUTPUT_STACK(int *stack, int top)
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


