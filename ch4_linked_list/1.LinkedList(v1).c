#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
struct listNode {
	int data;
	listPointer link;
};

void ListInsert(listPointer *first, listPointer x, int data);
void ListDelete(listPointer *first, listPointer trail, listPointer x);
listPointer ListSearchPrev(listPointer first, int data);
void ListPrint(listPointer first);

void main()
{
	listPointer first = NULL, x = NULL, trail = NULL;
	int num, i, data;
	
	printf("Enter the number of data items to be inserted into the Linked List: ");	
	scanf("%d", &num);
	for (i = 1; i <= num; i++)
	{
		printf("\nEnter the data item No.%d: ", i);
		scanf("%d", &data);
		ListInsert(&first, x, data);
		
		if (i == 1)
			x = first;
		else 
			x = x->link;
		
		printf("The data item %d has been added.\n", data);
	}	
	
	printf("\nEnter the data item to be deleted from the Linked List: ");	
	scanf("%d", &data);	
	printf("\n");
	
	trail = ListSearchPrev(first, data);
	if (trail)
	{
		ListDelete(&first, trail, trail->link);
		printf("The data item (value = %d) deleted!\n", data);
	}
	else
	{
		if (first->data == data)
		{
			ListDelete(&first, NULL, x);
			printf("The data item (value = %d) deleted!\n", data);
		}
		else
		    printf("The data item (value = %d) not found!\n", data);
	}
				
	ListPrint(first);
}

void ListInsert(listPointer *first, listPointer x, int data)
{
	listPointer temp;
	
	temp = (listPointer)malloc(sizeof(*temp));
	if (temp == NULL)
	{
		printf("Out of memory!\n");
		exit(1);
	}
	else
	{
		temp->data = data;
		if (*first)
		{
			temp->link = x->link;
			x->link = temp;
		}
		else
		{
			temp->link = NULL;
			*first = temp;
		}
	}
} 

void ListDelete(listPointer *first, listPointer trail, listPointer x)
{   // trail is the pointer to the preceding node of x 
	if (trail)
		trail->link = x->link;
	else
	{
		x = *first;
		*first = (*first)->link;
	}
	free(x);
}

listPointer ListSearchPrev(listPointer first, int data)
{
	for (; first->link != NULL; first = first->link)
		if ((first->link)->data == data)
			return first;

	return NULL;
}

void ListPrint(listPointer first)
{
	printf("The linked list contains:\n");
	for (; first != NULL; first = first->link)
		printf("%4d", first->data);
	printf("\n");
}
