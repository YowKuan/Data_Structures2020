#include <stdio.h>
#include <stdlib.h>

typedef struct listNode* listPointer;
struct listNode {
	int data;
	listPointer link;
};

void ListInsert(listPointer *first, listPointer x, int data);
void ListDelete(listPointer *first, listPointer trail, listPointer x);
listPointer ListSearch(listPointer first, int data); 
void ListPrint(listPointer first);


listPointer ListInvert(listPointer lead);
listPointer ListConcat(listPointer ptr1, listPointer ptr2);
listPointer CreateCircularList(listPointer OriginalSinglyList);
void Insert_front_CircularList(listPointer *last, listPointer node);
void CircularListPrint(listPointer last);
int CircularListLength(listPointer last);

void main()
{
	listPointer first = NULL, x = NULL, trail = NULL;
	listPointer Inv = NULL, Ptr1 = NULL, Ptr2 = NULL, last = NULL, node = NULL;
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
	ListPrint(first);
	
	printf("\nEnter the data item to be deleted from the Linked List: ");	
	scanf("%d", &data);	
	printf("\n");
	
	trail = ListSearch(first, data);
	if (trail)
	{
		ListDelete(&first, trail, trail->link);
		printf("The data item (value = %d) deleted!\n", data);
	}
	else
	{
		if (first->data == data)
		{
			ListDelete(&first, NULL, first);
			printf("The data item (value = %d) deleted!\n", data);
		}
		else
		    printf("The data item (value = %d) cannot found!\n", data);
	}
				
	ListPrint(first);
	
	printf("\nInverted list:\n");
	Inv = ListInvert(first);
	ListPrint(Inv);
	
	printf("Enter the number of data items to be inserted into the 2nd Linked List: ");	
	scanf("%d", &num);
	for (i = 1; i <= num; i++)
	{
		printf("\nEnter the data item No.%d: ", i);
		scanf("%d", &data);
		ListInsert(&Ptr2, x, data);
		
		if (i == 1)
			x = Ptr2;
		else 
			x = x->link;
		
		printf("The data item %d has been added.\n", data);
	}	
	
	Ptr1 = ListConcat(Inv, Ptr2);
	printf("After concatenation:\n");
	ListPrint(Ptr1);
	
	printf("\nCreate a Circular List:\n");
	last = CreateCircularList(Ptr1);
	CircularListPrint(last);
	printf("Insert a node to the front of the Circular List (input data):");
	node = (listPointer) malloc(sizeof(*node));
	scanf("%d", &(node->data));
	Insert_front_CircularList(&last, node);
	CircularListPrint(last);
	printf("\nThe length of the circular linked list = %d\n", CircularListLength(last));
}

listPointer CreateCircularList(listPointer OriginalSinglyList)
{
	listPointer temp, last;
	
	if (OriginalSinglyList != NULL)	
	{
		for(temp = OriginalSinglyList; temp->link != NULL; temp = temp->link);
		temp->link = OriginalSinglyList;
		last = temp;
	}
	else
	{
		printf("The original singly list is empty!\n");
		exit(1);
	} 
	
	return last;
}

void Insert_front_CircularList(listPointer *last, listPointer node)
{
//   /* insert node at the front of the circular list whose last node is last */
//	if (!(*last))
//	{
//    	/*  list is empty, change last to point to new entry */
//        *last = node;
//        node->link = node;
//	}
//   	else
//	{
//    	/* list is not empty, add new entry at front */
//        node->link = (*last)->link;
//        (*last)->link = node;
//	}
	
		if (!(*last))
	{
		*last = node;
		node->link = node;
	}
	else
	{
		node->link = (*last)->link;
		(*last)->link = node;	
	}
}

void CircularListPrint(listPointer last)
{
	listPointer first = last->link, temp;

	printf("\nThe circular linked list contains (from the first):\n");
	for (temp = first; temp->link != first; temp = temp->link)
		printf("%4d", temp->data);
	printf("%4d", temp->data); /* print the last node */
	printf("\n");	
}

int CircularListLength(listPointer last)
{
	/* find the length of circular list last */
	listPointer temp;
   	int count = 0;
   	if (last) 
	{
    	temp = last;
        do 
		{
	    	count++;
	     	temp = temp->link;
        } while (temp != last);
    }
    
    return count;
}

listPointer ListConcat(listPointer ptr1, listPointer ptr2)
{
	listPointer temp;
	
	if (!ptr1) 
		return ptr2;
    if (!ptr2)
		return ptr1;
    /* neither list is empty,  find end of first list */
    for(temp = ptr1; temp->link != NULL; temp = temp->link);
    /* linked end of first to start of second */
    temp->link = ptr2;	
    
    return ptr1;
}

listPointer ListInvert(listPointer lead)
{
	listPointer middle, trail;
    
	middle = NULL;
    
	while (lead) 
	{
    	trail = middle;
        middle = lead;
        lead = lead->link;
        middle->link = trail;
    }
    
	return middle;
}

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

listPointer ListSearch(listPointer first, int data)
{
	for (; first->link != NULL; first = first->link)
		if ((first->link)->data == data)
			return first;
			
	return NULL;		
}

void ListPrint(listPointer first)
{
	printf("\nThe linked list contains:\n");
	for (; first != NULL; first = first->link)
		printf("%4d", first->data);
	printf("\n");
}
