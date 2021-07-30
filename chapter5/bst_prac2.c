#include <stdio.h>
#include <stdlib.h>

typedef struct node* treepointer;
struct node{
	int data;
	treepointer left_child;
	treepointer right_child;
}; 


void bst_insert(treepointer *node, int data);
treepointer bst_modified_search(treepointer node, int data);
void inorder_print(treepointer ptr);
void preorder_print(treepointer ptr);
void postorder_print(treepointer ptr);



void main()
{
	treepointer node = NULL;
	int i, num, data;
	printf("Enter number insert in bst:\n");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("Enter bst No.%d: ", i);
		scanf("%d", &data);
		bst_insert(&node, data);

	}
	printf("The inorder result is:\n");
	inorder_print(node);
	printf("\n");
	
	printf("The preorder result is:\n");
	preorder_print(node);
	printf("\n");
	
	printf("The postorder result is:\n");
	postorder_print(node);
	printf("\n");
	
	
	
}

void bst_insert(treepointer *node, int data)
{
	treepointer temp = bst_modified_search(*node, data);
	treepointer ptr;
	
	if (temp || !(*node))
	{
		ptr = (treepointer)malloc(sizeof(*ptr));
		if (ptr == NULL)
		{
			printf("Mem full");
			exit(1);
		}
		ptr->data = data;
		ptr->left_child = NULL;
		ptr->right_child = NULL;
		
		if (*node)
		{
			if (data > (*node)->data)
			{
				temp->right_child = ptr;
			}
			else
				temp->left_child = ptr;	
		}
		else
			*node = ptr;
	}
	
}

treepointer bst_modified_search(treepointer node, int data)
{
	treepointer temp;
	
	if (!node)
		return NULL;
	while (node)
	{
		if (node->data == data)
			return NULL;
		if (data < node->data)
		{
			temp = node;
			node = node->left_child;
		}
		else
		{
			temp = node;
			node = node->right_child;
		}
	}
	return temp;
}

void inorder_print(treepointer ptr)
{
	if (ptr)
	{
		inorder_print(ptr->left_child);
		printf("%d ", ptr->data);
		inorder_print(ptr->right_child);
	}
}

void preorder_print(treepointer ptr)
{
	if (ptr)
	{
		printf("%d ", ptr->data);
		preorder_print(ptr->left_child);
		preorder_print(ptr->right_child);
	}
}

void postorder_print(treepointer ptr)
{
	if (ptr)
	{
		postorder_print(ptr->left_child);
		postorder_print(ptr->right_child);
		printf("%d ", ptr->data);
	}
}
