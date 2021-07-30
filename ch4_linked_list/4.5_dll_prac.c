#include <stdio.h>
#include <stdlib.h>

typedef struct doublenode* listpointer;
struct doublenode{
	int data;
	listpointer Llink;
	listpointer Rlink;
};

void double_link_insert(listpointer *first, listpointer node, int data);
void double_link_delete(listpointer *first, listpointer node, listpointer deleted); 
void double_print(listpointer first);
listpointer listsearch(listpointer first, int data);
void reversed_print(listpointer first);

void main()
{
	listpointer first = NULL, node = NULL, deleted = NULL;
	int i, num, data;
	printf("Enter the numbers in double linked list:\n");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("Enter the No.%d in the list:", i);
		scanf("%d", &data);
		double_link_insert(&first, node, data);
		
		//這邊要記得! 
		if (i ==1)
			node = first;
		else
			node = node->Rlink;
	}
	double_print(first);
	reversed_print(first);
	
	printf("Enter the data to be deleted:\n");
	scanf("%d", &num);
	node = listsearch(first, num);
	//注意! 
	double_link_delete(&first, node->Llink, node);
	double_print(first);
	reversed_print(first);
	
}

void double_link_insert(listpointer *first, listpointer node, int data)
{
	listpointer temp;
	temp = (listpointer)malloc(sizeof(temp));
	temp->data = data;
	
	if (!(*first))
	{
		temp->Llink = NULL;
		temp->Rlink = NULL;
		*first = temp;
	}
	else if(node->Rlink == NULL)
	{
		temp->Rlink = node->Rlink;
		node->Rlink = temp;
		temp->Llink = node;
	}
	else
	{
		temp->Rlink = node->Rlink;
		temp->Llink = node;
		(node->Rlink)->Llink = temp;
		node->Rlink = temp;
	}
 } 
 
void double_link_delete(listpointer *first, listpointer node, listpointer deleted)
{
	if (node)
	{
		node->Rlink = deleted->Rlink;
		if (deleted->Rlink !=NULL)
			(deleted->Rlink)->Llink = node;	
	}
	else
	{
		//有點莫名 可以問問看 
		deleted = *first;
		*first = (*first)->Rlink;
		(*first)->Llink = NULL;
	}
	free(deleted);
}

void double_print(listpointer first)
{
	printf("The double link is:\n");
	for (;first!=NULL; first = first->Rlink)
	{
		printf("%d ", first->data);
	 } 
	printf("\n");
}

listpointer listsearch(listpointer first, int data)
{
	for (;first != NULL; first = first->Rlink)
	{
		if (first->data == data)
			return first;
	}
	return NULL;
}

void reversed_print(listpointer first)
{
	printf("The reversed linked list is: \n");
	for (;first->Rlink != NULL; first = first->Rlink);
	for (; first != NULL; first = first->Llink)
	{
		printf("%d ", first->data);
	}
	printf("\n");
}

