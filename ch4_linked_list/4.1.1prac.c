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

void main()
{
	listpointer first = NULL, trail = NULL, x = NULL;
	int num, i, data;
	printf("Enter number inserted in linked list:");
	scanf("%d", &num);
	for(i = 1; i <= num; i++)
	{
		printf("Enter No. %d", i);
		scanf("%d", &data);
		listinsert(&first, x, data);
		
		if (i == 1)
			x=first;
		else
			x = x->link;
		printf("The data %d has been added\n", data);
	}
	
	listprint(first);
	printf("Enter number delete from linked list\n");
	scanf("%d", &data);
	
	trail = listsearchprev(first, data);
	if (trail)
	{
		listdelete(&first, trail, trail->link);
		printf("The number %d has been deleted\n", data);
	}
	else
	{
		if (first->data == data)
		{
			listdelete(&first, NULL, x);
			printf("The number %d has been deleted\n", data);
			
		}
		else
			printf("The number %d not found\n", data);
	}
	listprint(first);
}

void listinsert(listpointer *first, listpointer x, int data)
{
	listpointer temp;
	temp = (listpointer) malloc(sizeof(*temp));
	if (temp == NULL)
	{
		printf("Not enough memory!");
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


void listdelete(listpointer *first, listpointer trail, listpointer x)
{
	if (trail)
	{
		trail->link = x->link;
		 
	}
	else
	{
		*first = (*first)->link;
	}
	free(x);
}

listpointer listsearchprev(listpointer first, int data)
{
	for (;first->link!=NULL; first = first->link)
	{
		if ((first->link)->data == data)
			return first;
	} 
	return NULL;
}

void listprint(listpointer first)
{
	printf("Current list is:\n");
	/////
	for (; first!= NULL; first = first->link)
	{
		printf("%4d", first->data);
	}
	printf("\n");
}

