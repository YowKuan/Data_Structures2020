#include <stdio.h>
#include <stdlib.h>
#define MAX_CIR_QUEUE 10

typedef struct{
	int key;
}element;

void addq(element *queue, int front, int *rear, element item);
element deleteq(element *queue, int *front, int rear);
void queue_empty();
void queue_full();
void OUTPUT_QUEUE(element *queue, int front, int rear);

void main(){
	element queue[MAX_CIR_QUEUE];
	element item;
	int i, num;
	int front = -1;
	int rear = -1;
	
	printf("\nEnter amount of number add in queue:");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++){
		printf("Enter NO.%d:", i);
		scanf("%d", &item.key);
		printf("%d has been added\n" , item.key);
		addq(queue, front, &rear, item);	
	}
	printf("\nEnter amount of number remove from queue:");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++){
		deleteq(queue, &front, rear);	
	}
	printf("\nCurrent front %d", front);
	printf("\nCurrent rear %d", rear);
	printf("\nResult is:\n");
	OUTPUT_QUEUE(queue, front, rear);
	
	printf("\nEnter amount of number add in queue:");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++){
		printf("Enter NO.%d:", i);
		scanf("%d", &item.key);
		printf("%d has been added\n" , item.key);
		addq(queue, front, &rear, item);	
	}
	printf("\nCurrent front %d", front);
	printf("\nCurrent rear %d", rear);
	printf("\nResult is:\n");
	OUTPUT_QUEUE(queue, front, rear);
	
	
	
}

void addq(element *queue, int front ,int *rear, element item){
	*rear = (*rear+1) % MAX_CIR_QUEUE;
	if(*rear == front){
		printf("\nCurrent front %d", front);
		printf("\nCurrent rear %d", *rear);
		queue_full();

	}
	else{
		queue[*rear] = item; 
	}
}

element deleteq(element *queue, int *front, int rear){
	if (rear == *front){
		queue_empty();
	}
	else{
		return queue[(*front)++];
	}
}

void queue_full(){
	printf("\nQueue full!\n");
	exit(1);
}

void queue_empty(){
	printf("Queue empty!\n");
	exit(1);
}

void OUTPUT_QUEUE(element *queue, int front, int rear){
	int i;
	if (rear == front){
		queue_empty();
	} 
	else{
		if (rear > front){
			for (i=front+1 ; i <= rear; i++){
				printf("%d ", queue[i].key);
			}}
		else{
			for (i = front+1; i<= MAX_CIR_QUEUE-1; i++)
				printf("%d ", queue[i].key);
			for (i = 0; i <= rear; i++)
				printf("%d ", queue[i].key);			
		}
		}
	}

