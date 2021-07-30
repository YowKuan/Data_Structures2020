#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE 10

typedef struct{
	int key;
}element;

void addq(element *queue, int *rear, element item);
element deleteq(element *queue, int *front, int rear);
void queue_empty();
void queue_full();
void Output_queue(element *queue, int front, int rear);

void main()
{
	element queue[MAX_QUEUE];
	int num, i;
	element item;
	int front = -1;
	int rear = -1;
	
	printf("Please enter the amount of numbers add into queue:");
	scanf("%d", &num);
	
	for(i=1; i<=num;i++){
		printf("\nPlease enter queue NO.%d ", i);
		scanf("%d", &item.key);
		addq(queue, &rear, item);
		printf("%d has been added\n", item.key);	
	}
	
	printf("Please enter the amount of numbers remove from queue:");
	scanf("%d", &num);
	
	for(i=1; i<=num;i++){
		item = deleteq(queue, &front, rear);
		printf("The number %d has been deleted\n", item.key);
	}
	
	printf("The result is:");
	Output_queue(queue, front, rear);
}

void addq(element *queue, int *rear, element item)
{
	if (*rear == MAX_QUEUE-1){
		queue_full();
	}
	else{
		queue[++(*rear)] = item;
	}
}

element deleteq(element *queue, int *front, int rear){
	if (*front == rear){
		queue_empty();
	}
	else{
		return queue[++(*front)];
	}
}

void queue_empty(){
	printf("Queue is empty!\n");
	exit(1);
}

void queue_full(){
	printf("Queue is full!\n");
	exit(1);
}

void Output_queue(element *queue, int front, int rear){
	int i;
	if (front == rear){
		queue_empty();
	}
	else{
		for (i = ++front; i <= rear; i++)
		printf("%d ", queue[i].key);
	}
	
}
