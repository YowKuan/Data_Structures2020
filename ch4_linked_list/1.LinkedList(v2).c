#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
struct listNode {
	int data;
	listPointer link;
};

void ListInsert(listPointer *first, listPointer x, int data);
void ListPrint(listPointer first);
listPointer ListSearch(listPointer first, int data);
listPointer ListSearchPrev(listPointer first, int data);
void ListDelete(listPointer *first, listPointer trail, listPointer x);

void main()
{
	listPointer first = NULL, x = NULL, trail = NULL;
	int num, i, data;
	
	printf("Enter the number of data item: ");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("Enter the data item No.%d: ", i);
		scanf("%d", &data);
		ListInsert(&first, x, data);
		if (i == 1)
			x = first;
		else
			x = x->link;
	}
	
	ListPrint(first);
	
	x = ListSearch(first, 20);
	if (x)
	{
		ListInsert(&first, x, 25);
		printf("The data item 25 is inserted!\n");
	}
	ListPrint(first);
	
	trail = ListSearchPrev(first, 25);
	if (trail)
	{
		ListDelete(&first, trail, trail->link);
		printf("The data item 25 is deleted!\n");
	}
	else
	{
		if (first->data == 25)
		{
			ListDelete(&first, NULL, x);
			printf("The data item 25 is deleted!\n");
		}
		else
		    printf("The data item 25 cannot found!\n");		
	}
	ListPrint(first);
	
	trail = ListSearchPrev(first, 50);
	if (trail)
	{
		ListDelete(&first, trail, trail->link);
		printf("The data item 50 is deleted!\n");
	}
	else
	{
		if (first->data == 50)
		{
			ListDelete(&first, NULL, x);
			printf("The data item 50 is deleted!\n");
		}
		else
		    printf("The data item 50 cannot found!\n");			
	}
	ListPrint(first);
}
// call by address
void ListInsert(listPointer *first, listPointer x, int data)
{
	listPointer temp;
	temp = (listPointer) malloc(sizeof(*temp));
	if (temp == NULL)
	{
		printf("Out of memory!\n");
		exit(1);
	}
	else
	{
		temp->data = data;
		if (*first != NULL)   
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

void ListPrint(listPointer first)
{
	printf("The linked list contains: \n");
	for ( ; first != NULL; first = first->link)
		printf("%4d", first->data);
	printf("\n");
}

listPointer ListSearch(listPointer first, int data)
{
	for (; first != NULL; first = first->link)
		if (first->data == data)
			printf("data foundddd ");
			return first;
	printf("%d cannot be found!\n");
	
	return NULL;
}

listPointer ListSearchPrev(listPointer first, int data)
{
	for (; first->link != NULL; first = first->link)
		if ((first->link)->data == data)
			return first;
	
	return NULL;
}

void ListDelete(listPointer *first, listPointer trail, listPointer x)
{
	if (trail)
		trail->link = x->link;
	else
	{
		x = *first;
		*first = (*first)->link;
	}
	free(x);
}






















