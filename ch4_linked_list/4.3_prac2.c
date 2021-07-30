#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int key;
}element;

typedef struct queue* queue_pointer;
struct queue{
	element data;
	queue_pointer link;
};


void addq(queue_pointer *front, queue_pointer *rear, element item);
element deleteq(queue_pointer *front);
void queueprint(queue_pointer front);

void main()
{
	queue_pointer front = NULL, rear = NULL; 
	element item;
	int i, num;
	printf("Enter number in queue: \n");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("Enter No.%d in queue: ", i);
		scanf("%d", &item.key);
		addq(&front, &rear, item);
	}
	queueprint(front);
	
	printf("Enter number delete from queue: \n");
	scanf("%d", &num);
	
	for (i = 1; i<= num; i++)
	{
		item = deleteq(&front);
		printf("The element %d has been deleted\n", item.key);
	}
	queueprint(front);
	
	
	
}



void addq(queue_pointer *front, queue_pointer *rear, element item)
{
	queue_pointer temp;
	temp = (queue_pointer)malloc(sizeof(*temp));
	
	if (temp == NULL)
	{
		printf("Mem full");
		exit(1);
	}
	temp->data = item;
	temp->link = NULL;
	
	if (*front)
	{
		(*rear)->link = temp;
	}
	else
	{
		*front = temp;
	}
	*rear = temp;
}

element deleteq(queue_pointer *front)
{
	queue_pointer temp = *front;
	element item;
	
	if (temp == NULL)
	{
		printf("Queue empty");
		exit(1);
	}
	
	item = temp->data;
	*front = (*front)->link;
	free(temp);
	
	return item;
}

void queueprint(queue_pointer front)
{
	printf("The current queue is:\n");
	for(;front != NULL; front = front->link)
	{
		printf("%d ", front->data);
	}
	printf("\n");
}
