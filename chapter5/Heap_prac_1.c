#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENTS 200

typedef struct{
	int key;
}element;

void Heap_Push(element item, int *n, element *heap);
element Heap_Delete(element *heap, int *n);
void Heap_Print(element *heap, int n);

void main()
{
	element heap[MAX_ELEMENTS], item;
	int i, num;
	int n = 0; 
	
	printf("Enter numbers insert into heap:");
	scanf("%d", &num);
	
	for (i=1 ; i<=num; i++)
	{
		printf("Enter heap number %d: ", i);
		scanf("%d", &(item.key));
		Heap_Push(item, &n, heap);
	}
	Heap_Print(heap, n);
	
	while (n>0)
	{
		item = Heap_Delete(heap, &n);
		printf("Deleted: %d\n", item.key);
		printf("Current Heap is:");
		Heap_Print(heap, n);
	}
	
}

void Heap_Push(element item, int *n, element *heap)
{
	int i;
	if (*n == MAX_ELEMENTS -1)
	{
		printf("Heap full");
		exit(1);
	}
	i = ++(*n);
	
	while ((i != 1) && (item.key > heap[i/2].key))
	{
		heap[i] = heap[i/2];
		i /= 2;
	}
	heap[i] = item;
 } 
 
element Heap_Delete(element *heap, int *n)
{
	element item, temp;
	int parent, child;
	if (*n ==0)
	{
		printf("Heap is empty");
		exit(1);
	}
	
	item = heap[1];
	temp = heap[(*n)--];
	
	parent = 1;
	child = 2;
	
	while (child <= (*n))
	{
		if ((child < *n) && (heap[child].key < heap[child+1].key))
		{
			child ++;
		}
		if (temp.key >= heap[child].key)
			break;
		heap[parent] = heap[child];
		parent = child;
		child *=2;	
	heap[parent] = temp;
	return item;
		
	 } 
}

void Heap_Print(element *heap, int n)
{
	int i;
	for (i = 1; i <= n ; i++)
	{
		printf("%d ", heap[i].key);
	}
	printf("\n");
}
