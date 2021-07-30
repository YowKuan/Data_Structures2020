#include <stdio.h>
#include <stdlib.h>

typedef struct dll* listpointer;
struct dll{
	int data;
	listpointer llink;
	listpointer rlink;
};

void dll_print(listpointer first);
void reversed_dll(listpointer first);
void dll_insert(listpointer *first, listpointer node, int new_data);
void dll_delete(listpointer *first, listpointer node, listpointer deleted);
listpointer listsearch(listpointer first, int data);

void main()
{
	listpointer first = NULL, node = NULL;
	int i, num, data;
	printf("number in dll: ");
	scanf("%d", &num);
	
	for (i = 1; i<= num; i++)
	{
		printf("Enter No.%d in dll: ", i);
		scanf("%d", &data);
		dll_insert(&first, node, data);
		
		if (i == 1)
			node = first;
		else
			node = node->rlink;
	 } 
	dll_print(first);
	reversed_dll(first);
	
	printf("Enter number you want to delete: \n");
	scanf("%d", &data);
	node = listsearch(first, data);
	dll_delete(&first, node->llink, node);
	
	dll_print(first);
	reversed_dll(first);
}

void dll_insert(listpointer *first, listpointer node, int new_data)
{
	listpointer temp;
	temp = (listpointer)malloc(sizeof(*temp));
	
	temp->data = new_data;
	
	if (!(*first))
	{
		*first = temp;
		temp->llink = NULL;
		temp->rlink = NULL;
	}
	else if(node->rlink == NULL)
	{
		node->rlink = temp;
		temp->rlink = NULL;
		temp->llink = node;
	}
	else
	{
		(node->rlink)->llink = temp;
		temp->rlink = node->rlink;
		temp->llink = node;
		node->rlink = temp;
	}
}

void dll_delete(listpointer *first, listpointer node, listpointer deleted)
{
	if (node)
	{
		node->rlink = deleted->rlink;
		if (deleted->rlink != NULL)
			(deleted->rlink)->llink = deleted->llink; 
	}
	else
	{
		deleted = *first;
		*first = (*first)->rlink;
		(*first)->llink = NULL;
	}
	free(deleted);
}

void dll_print(listpointer first)
{
	printf("The dll is:\n");
	for (; first != NULL; first = first->rlink)
		printf("%d ", first->data);
	printf("\n");
}

listpointer listsearch(listpointer first, int data)
{
	for (;first != NULL; first = first->rlink)
	{
		if (first->data == data)
			return first;
	}
	return NULL;
}

void reversed_dll(listpointer first)
{
	printf("The reversed dll is:\n");
	for (; first->rlink != NULL; first = first->rlink);
	for (; first != NULL; first = first->llink)
		printf("%d ", first->data);
	printf("\n");
		

}
