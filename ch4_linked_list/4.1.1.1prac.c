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
listpointer listconcat(listpointer ptr1, listpointer ptr2);
listpointer createcircular(listpointer originallist);
void insert_front_circularlist(listpointer *last, listpointer node);
void circularlistprint(listpointer last);
int circularlistlength(listpointer last);


void main()
{
	//注意 
	listpointer first = NULL, trail = NULL, x = NULL;
	int i, number, data;
	printf("Enter the numbers you want to insert:");
	scanf("%d", &number);
	
	listpointer Inv = NULL;
	listpointer ptr1 = NULL, ptr2 = NULL, last = NULL, node = NULL;;
	
	for (i = 1; i<=number; i++)
	{
		printf("Insert number %d: ", i);
		scanf("%d", &data);
		listinsert(&first, x, data);
		
		if (i==1)
		{
			x = first;
		}
		else
		{
			x = x->link;
		}
		printf("The data %d has been added\n", data);
	}
	
	printf("Current linked list is:\n");
	listprint(first);
	
	printf("Enter the data to be deleted from linked list:");
	scanf("%d", &data);
	
	trail = listsearchprev(first, data);
	if (trail)
	{
		//
		listdelete(&first, trail, trail->link);
		printf("The data %d has been deleted\n", data);
	}
	else
	{
		if (first->data == data)
		{
			//why x?
			listdelete(&first, NULL, x);
			printf("The data %d has been deleted\n", data);
		}
		else
		{
			printf("Data %d not found\n", data);
		}
	}
	
	listprint(first);
	
	printf("\nInverted list:\n");
	Inv = listinvert(first);
	listprint(Inv);
	
	printf("Enter the numbers you want to insert in the second list:");
	scanf("%d", &number);
	
	for (i = 1; i<=number; i++)
	{
		printf("Insert number %d: ", i);
		scanf("%d", &data);
		listinsert(&ptr2, x, data);
		
		if (i==1)
		{
			x = ptr2;
		}
		else
		{
			x = x->link;
		}
		printf("The data %d has been added\n", data);
	}
	printf("The second list is:\n");
	listprint(ptr2);
	
	ptr1 = listconcat(Inv, ptr2);
	printf("The concated result is:\n");
	listprint(ptr1);
	
	printf("Create a circular list:\n");
	last = createcircular(ptr1);
	circularlistprint(last);
	
	
	printf("insert a node in front of the circular list:");
	scanf("%d", &(node->data));
	node = (listpointer) malloc(sizeof(*node));
	insert_front_circularlist(&last, node);
	circularlistprint(last);
	
	printf("\nThe length of the circular linked list = %d\n", circularlistlength(last));
	
	
}

listpointer listinvert(listpointer lead)
{
	listpointer middle, trail;
	middle = NULL;
	
	while (lead)
	{
		trail = middle;
		middle = lead;
		lead = lead->link;
		middle->link = trail;
	}
	//middle應該是最後一個數字? 
	return middle;
}

listpointer listconcat(listpointer ptr1, listpointer ptr2)
{
	listpointer temp;
	if (!ptr1)
		return ptr2;
	if (!ptr2)
		return ptr1;
	
	for (temp = ptr1 ;temp->link != NULL; temp = temp->link);
	temp->link = ptr2;
	
	return ptr1;
}

listpointer createcircular(listpointer originallist)
{
	listpointer temp, last;
	if (originallist != NULL)
	{
		for (temp = originallist; temp->link != NULL; temp = temp->link);
		last = temp;
		last->link = originallist;
	}
	else
	{
		printf("list is empty");
		exit(1);
	}
	
	return last;

}

void insert_front_circularlist(listpointer *last, listpointer node)
{
	if (!*last)
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

void circularlistprint(listpointer last)
{
	listpointer first = last->link, temp;
	
	for (temp = first; temp->link !=first; temp = temp->link)
	{
		printf("%4d ", temp->data);
	}
	printf("%4d", temp->data);
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
		}while(temp!=last);
	}
}



void listinsert(listpointer *first, listpointer x, int data)
{
	listpointer temp;
	
	temp = (listpointer)malloc(sizeof(*temp));
	if (temp == NULL)
	{
		printf("No memory left");
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
			*first = temp;
			temp->link = NULL;
		}
	}
}

listpointer listsearchprev(listpointer first, int data)
{
	for ( ;first->link != NULL; first = first->link )
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
		//x = *first 意義是啥? 
		x = *first;
		*first = (*first)->link;
	}
	free(x);
}

void listprint(listpointer first)
{
	printf("The linked list is: ");
	for (; first != NULL; first = first->link)
	{
		printf("%4d", first->data);
	}
	printf("\n");
}
