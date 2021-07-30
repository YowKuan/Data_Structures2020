#include <stdio.h>
#include <stdlib.h>

typedef struct listnode* listpointer;
struct listnode{
	int data;
	listpointer link;
}; 

void listinsert(listpointer *first, listpointer x, int data);
void listdelete(listpointer *first, listpointer trail, listpointer x);
listpointer listsearchprev(listpointer first, int data);
void listprint(listpointer first);

listpointer listinvert(listpointer lead);
listpointer createcircularlist(listpointer originallist);
void insertfront_circular(listpointer *last, listpointer node);
listpointer createcircularlist(listpointer originallist);
listpointer listconcat(listpointer ptr1, listpointer ptr2);
void circularlistprint(listpointer last);
int circularlistlength(listpointer last);


void main()
{
	listpointer first = NULL, x = NULL, trail = NULL, node = NULL, ptr1 = NULL, ptr2 = NULL, last = NULL, Inv = NULL;
	int i, num, data, count;
	printf("Enter numbers entered in linked list: \n");
	scanf("%d", &num);
	
	for (i = 1; i<= num; i++)
	{
		printf("Enter No.%d inserted into linked list:\n", i);
		scanf("%d", &data);
		listinsert(&first, x, data);
		
		if (i == 1)
		{
			x = first;
		}
		else
		{
			x = x->link;
		}
	}
	listprint(first);
	
	printf("Enter the number you want to delete: ");
	scanf("%d", &data);
	
	trail = listsearchprev(first, data);
	
	if (trail)
	{
		listdelete(&first, trail, trail->link);
		printf("The number %d is deleted\n.", data);
	}
	else
	{
		if (first->data == data)
		{
			listdelete(&first, NULL, first);
			printf("The number %d is deleted\n.", data);
		}
		else
		{
			printf("The number %d does not exist.\n", data);
		}
	}
	listprint(first);
	
	printf("The inverted list is:\n");
	Inv = listinvert(first);
	listprint(Inv);
	
	
	last = createcircularlist(Inv);
	circularlistprint(last);
	
	printf("Enter the number enter in circular list:\n");
	node = (listpointer)malloc(sizeof(*node));
	scanf("%d", &(node->data));

	insertfront_circular(&last, node); 
	circularlistprint(last);
	
	
	count = circularlistlength(last);
	printf("%d", count);

	
	
	
}

listpointer createcircularlist(listpointer originallist)
{
	listpointer temp, last;
	
	if (originallist != NULL)
	{
		for (temp = originallist; temp->link != NULL; temp = temp->link);
		temp->link = originallist;
		last = temp;
	}
	else
	{
		printf("The list is empty");
		exit(1);
	}
	return last;
	
}

void insertfront_circular(listpointer *last, listpointer node)
{
	if (*last)
	{
		node->link = (*last)->link;
		(*last)->link = node;
	}
	else
	{
		*last = node;
		node->link = node;
	}
}

void circularlistprint(listpointer last)
{
	listpointer first = last->link;
	listpointer temp;
	
	printf("The circular list is:\n");
	for(temp = first; temp != last; temp = temp->link)
	{
		printf("%d ", temp->data);
	}
	printf("%d ", temp->data);
	printf("\n");
}

int circularlistlength(listpointer last)
{
	listpointer temp;
	int count = 0;
	if (last)
	{
		temp = last;
		do
		{
			count++;
			temp = temp->link;
		}while(temp != last);
	}
	return count;
}


listpointer listinvert(listpointer lead)
{
	listpointer trail, middle;
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

listpointer listconcat(listpointer ptr1, listpointer ptr2)
{
	listpointer temp;
	if (ptr1 == NULL)
		return ptr2;
	if (ptr2 == NULL)
		return ptr1;
	
	for (temp = ptr1 ;temp->link != NULL; temp = temp->link);
	temp->link = ptr2;
	
	return ptr1;
}

void listinsert(listpointer *first, listpointer x, int data)
{
	listpointer temp;
	temp = (listpointer)malloc(sizeof(*temp));
	if (temp ==NULL)
	{
		printf("mem full");
		exit(1);
	}
	
	temp->data  = data;
	
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



listpointer listsearchprev(listpointer first, int data)
{
	for (; first->link != NULL; first = first->link)
	{
		if ((first->link)->data == data)
			return first;
	}
	return NULL;
	
}


void listdelete(listpointer *first, listpointer trail, listpointer x)
{
	if (trail)
	{
		trail->link = x->link;
	}
	else
	{
		x = *first;
		*first = (*first)->link;
	}
	free(x); 
}

void listprint(listpointer first)
{
	for (; first != NULL; first = first->link)
	{
		printf("%d ", first->data);
	}
	printf("\n");
}



