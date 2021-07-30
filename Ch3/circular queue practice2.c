#include <stdlib.h>
#include <stdio.h>
#define MAX_QUEUE 10

typedef struct{
	int key;
}element;

void addq(element *queue, int *rear, int front, element item);
element deleteq(element *queue, int *front, int rear);
void queue_full();
void queue_empty();
void OUTPUT_QUEUE(element *queue, int front, int rear);

void main()
{
	element
	queue[MAX_QUEUE];
	int i, num;
	element item;
	int rear = 0;
	int front = 0;
	printf("Current front and rear are: %d, %d\n", front, rear);
	printf("Type the amount of numbers you want to add in: \n");
	scanf("%d", &num);
	
	for (i = 1; i<= num; i++)
	{
		printf("Add queue number %d: \n", i);
		scanf("%d", &item.key);
		addq(queue, &rear, front, item);//
	}
	OUTPUT_QUEUE(queue, front, rear);
	printf("Current front and rear are: %d, %d\n", front, rear);
	printf("Type the amount of numbers you want to delete: \n");
	scanf("%d", &num);
	
	for (i = 1; i<= num; i++)
	{
		deleteq(queue, &front, rear);
	}
	printf("Current queue is:\n");
	OUTPUT_QUEUE(queue, front, rear);
	printf("Current front and rear are: %d, %d\n", front, rear);
	
	printf("Type the amount of numbers you want to add in: \n");
	scanf("%d", &num);
	
	for (i = 1; i<= num; i++)
	{
		printf("Add queue number %d: \n", i);
		scanf("%d", &item.key);
		addq(queue, &rear, front, item);//
	}
	OUTPUT_QUEUE(queue, front, rear);
	printf("Current front and rear are: %d, %d\n", front, rear);
	
}

void addq(element *queue, int *rear, int front, element item)
{
	*rear = (*rear+1) % MAX_QUEUE;// 
	if (front == *rear)
		queue_full();
	else
	{
		queue[(*rear)] = item;
	}	
 } 
 
element deleteq(element *queue, int *front, int rear)
{
	if (*front == rear)
		queue_empty();
	else
	{
		*front = (*front +1) % MAX_QUEUE;
		return queue[(*front)];
	}
	
		
}

void queue_full()
{
	printf("QUEUE full!!!");
	exit(1);
}

void queue_empty()
{
	printf("QUEUE empty!!!");
	exit(1);
}

void OUTPUT_QUEUE(element *queue, int front, int rear)
{
	int i;
	if (front == rear)
		queue_empty();
	else
		if (rear > front)
		{
			for (i = front+1; i<=rear; i++)
				printf("%d ", queue[i].key);
		}
		else
		{
			for (i =front+1; i<= MAX_QUEUE-1; i++)
				printf("%d ", queue[i].key);
			for (i = 0; i <= rear; i++)
				printf("%d ", queue[i].key);
			
		}
}
