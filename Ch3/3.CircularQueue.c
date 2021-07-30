#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10 /*maximum stack size*/

typedef struct {
	int key;
    /* other fields */
 } element;
void addq(element *queue, int front, int *rear, element item);
element deleteq(element *queue, int *front, int rear);
void queue_full();
void queue_empty();
void Output_queue(element *queue, int front, int rear);

void main()
{
	element queue[MAX_QUEUE_SIZE];
 	int rear = 0;
	int front = 0;
 	int num, i;
	element item;
	
	printf("Enter the number (at most %d) of data items to be added into the queue: ", MAX_QUEUE_SIZE - 1);	
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("\nEnter the data item No.%d: ", i);
		scanf("%d", &item.key);
		addq(queue, front, &rear, item);
		printf("The data item %d has been added.\n", item.key);
	}

	printf("\nEnter the number of data items to be deleted from the queue: ");	
	scanf("%d", &num);	
	printf("\n");

	for (i = 1; i <= num; i++)
	{
		item = deleteq(queue, &front, rear);
		printf("The data item No.%d (with key value = %d) deleted!\n", i, item.key);
	}	
	
	printf("The current data items in the queue include:\n");
	Output_queue(queue, front, rear);	
	
	printf("\n\n(Again) Enter the number of data items to be added into the queue: ");	
	scanf("%d", &num);
	for (i = 1; i <= num; i++)
	{
		printf("\nEnter the data item No.%d: ", i);
		scanf("%d", &item.key);
		addq(queue, front, &rear, item);
		printf("The data item %d has been added.\n", item.key);
	}
	printf("The current data items in the queue include:\n");
	Output_queue(queue, front, rear);	
}

void addq(element *queue, int front, int *rear, element item)
{
    *rear = (*rear + 1) % MAX_QUEUE_SIZE;
    if (front == *rear) 
	   	queue_full(); 
    else
    	queue[*rear] = item;
}

element deleteq(element *queue, int *front, int rear)
{
    if (*front == rear)
    	queue_empty();    
    else
    {
		*front = (*front + 1) % MAX_QUEUE_SIZE;
    	return queue[*front];
	}
}

void queue_full()
{
	printf("Queue full!\n");
	exit(1); 
}

void queue_empty()
{
	printf("Queue empty!\n");
	exit(1); 	
}

void Output_queue(element *queue, int front, int rear)//和一般的queue比較不一樣 注意!(else那邊) 
{
	int i;

    if (front == rear)
    	queue_empty(); 
	else
	{
		if (front < rear)	
			for (i = (front + 1); i <= rear; i++)
				printf("%d ", queue[i].key);
		else
		{
			for (i = (front + 1); i <= MAX_QUEUE_SIZE - 1; i++)//印front+1到0前一格之間的值 
				printf("[%d]%d ", i, queue[i].key);
			for (i = 0; i <= rear; i++)//印0 到rear之間的值 
				printf("[%d]%d ", i, queue[i].key);
		}
	}
}
