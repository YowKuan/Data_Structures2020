#include <stdio.h>
#include <stdlib.h>

typedef struct listnode* listpointer;
struct listnode{
	int data;
	listpointer link;
};

void ListInsert(listPointer *first, listPointer x, int data);
void ListDelete(listPointer *first, listPointer trail, listPointer x);
listPointer ListSearch(listPointer first, int data); 
void ListPrint(listPointer first);



void main()
{
	listpointer first = NULL, x = NULL, trail = NULL;
	int i,num, data;
	printf("Enter number want to insert in linked list:\n");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("Enter the data number %d: ", i);
		scanf("%d", &data);
		listinsert(&first, x, data);
		
		if (i == 1)
			x = first;
		else
			x = x->link;
			
		printf("The number %d has been added\n", data);
	}
	listprint(first);
	
	printf("Enter number want to delete from linked list:\n");
	scanf("%d", &data);
	
	trail = listsearch(first, data);
	
	if (trail)
	{
		//注意此處trail->link部分 
		listdelete(&first, trail, trail->link);
		printf("The data %d has been deleted", data);
	}
	else
	{
		if (first->data == data)
		{
			//注意delete的輸入值 
			listdelete(&first, NULL, x);
			printf("The data %d has been deleted", data);
		}
		else
		{
			printf("The data %d is not found.", data); 
		}
			
	}
	listprint(first);
}

void listinsert(listpointer *first, listpointer x, int data)
{
	listpointer temp;
	temp = (listpointer)malloc(sizeof(temp));
	if (!temp)
	{
		printf("Memory not enough!");
		exit(1);
	}
	else
		printf("Mem enough");
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
//		printf("First num added");
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
		//difficult...
		x = *first;
		*first = (*first)->link;
	}
	free(x);
}

void listprint(listpointer first)
{
	printf("Current linked list is:\n");
	for (;first != NULL; first = first->link)
	{
		printf("%d ", first->data);
	}
}

listpointer listsearch(listpointer first, int data)
{
	for(;first->link !=NULL; first = first->link)
	{
		if ((first->link)->data == data)
			return first;
	}
	return NULL;
}
