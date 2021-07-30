#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10 /*maximum stack size*/
//

typedef struct {
	int key;
    /* other fields */
 } element;
void addq(element *queue, int *rear, element item); //*queue¥i¥H¼g¦¨queue[] 
element deleteq(element *queue, int *front, int rear);
void queue_full();
void queue_empty();
void Output_queue(element *queue, int front, int rear);

void main()
{
	element queue[MAX_QUEUE_SIZE];
 	int rear = -1;
	int front = -1;
 	int num, i;
	element item;
	
	printf("Enter the number of data items to be added into the queue: ");	
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("\nEnter the data item No.%d: ", i);
		scanf("%d", &item.key);
		addq(queue, &rear, item);
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
		addq(queue, &rear, item);
		printf("The data item %d has been added.\n", item.key);
	}
	printf("The current data items in the queue include:\n");
	Output_queue(queue, front, rear);	
}

void addq(element *queue, int *rear, element item)
{
	if (*rear == MAX_QUEUE_SIZE - 1) 
    	queue_full();
    else
    	queue[++(*rear)] = item;
}

element deleteq(element *queue, int *front, int rear)
{
    if (*front == rear)
    	queue_empty(); 
    else
    	return queue[++(*front)];
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

void Output_queue(element *queue, int front, int rear)
{
	int i;

    if (front == rear)
    	queue_empty(); 
	else	
		for (i = (++front); i <= rear; i++)
			printf("%d ", queue[i].key);
}
