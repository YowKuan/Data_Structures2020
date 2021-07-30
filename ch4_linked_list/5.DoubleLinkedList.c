#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
struct listNode {
	listPointer Llink;
	int data;
	listPointer Rlink;
};

void DoubleListInsert(listPointer *first, listPointer node, int new_node_data);
void ListPrint(listPointer first);
listPointer ListSearch(listPointer first, int data);
void InverseListPrint(listPointer first);
void DoubleListDelete(listPointer *first, listPointer node, listPointer deleted);

void main()
{
	listPointer first = NULL, node = NULL;
	int num, i, data;
	
	printf("Enter the number of data item: ");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("Enter the data item No.%d: ", i);
		
		scanf("%d", &data);
		DoubleListInsert(&first, node, data);
		
		if (i == 1)
			node = first;
		else
			node = node->Rlink;
	}
	ListPrint(first);
	
	printf("Enter the data to be found: ");
	scanf("%d", &data);
	node = ListSearch(first, data);
	printf("Enter the data to be inserted after the data %d: ", data);
	scanf("%d", &data);
	DoubleListInsert(&first, node, data);
	ListPrint(first);
	
	printf("Enter the data to be deleted: ", data);
	scanf("%d", &data);
	node = ListSearch(first, data);
	DoubleListDelete(&first, node->Llink, node);
	ListPrint(first);
	InverseListPrint(first);
}

void DoubleListInsert(listPointer *first, listPointer node, int new_node_data)
{
	listPointer temp = (listPointer) malloc(sizeof(*temp));
	temp->data = new_node_data;
	
	if (!(*first))
	{
		/* if empty list, new_node is the first node */
		temp->Rlink = NULL;
		temp->Llink = NULL;
		*first = temp;
	}
	else if (node->Rlink == NULL)
	{
		/* new_node is the last node */
    	temp->Llink = node;
    	temp->Rlink = node->Rlink;		
    	node->Rlink = temp;
	}
	else
	{
		/* new_node is a middle node */ 
    	temp->Llink = node;
    	temp->Rlink = node->Rlink;
    	(node->Rlink)->Llink = temp;
    	node->Rlink = temp;
	}
}

void ListPrint(listPointer first)
{
	printf("The linked list contains: \n");
	for ( ; first != NULL; first = first->Rlink)
		printf("%4d", first->data);
	printf("\n");
}

listPointer ListSearch(listPointer first, int data)
{
	for (; first != NULL; first = first->Rlink)
		if (first->data == data)
			return first;
	return NULL;
}

void DoubleListDelete(listPointer *first, listPointer node, listPointer deleted)
{
	if (node)
	{
		deleted->Llink->Rlink = deleted->Rlink;
		if (deleted->Rlink != NULL)
        	deleted->Rlink->Llink = deleted->Llink;
	}
	else
	{
		deleted = *first;
		*first = (*first)->Rlink;
		(*first)->Llink = NULL;
	}
	free(deleted);
}

void InverseListPrint(listPointer first)
{
	printf("The inversed linked list contains: \n");
	for ( ; first->Rlink != NULL; first = first->Rlink);
	for ( ; first != NULL; first = first->Llink)
		printf("%4d", first->data);
	printf("\n");
}
