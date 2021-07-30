#include <stdio.h>
#include <stdlib.h>

typedef struct node* treepointer;
struct node{
	int data;
	treepointer left_child, right_child;
};

void bst_insert(treepointer *node, int num);
treepointer bst_modified_search(treepointer tree, int key);
void inorder_print(treepointer ptr);
treepointer bst_findmin(treepointer node);

void main()
{
	treepointer root = NULL, min = NULL;
	int i, num, data;
	printf("Enter numbers you want to insert in bst:\n");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("Enter bst No.%d: ", i);
		scanf("%d", &data);
		bst_insert(&root, data);

	}
	inorder_print(root);
	min = bst_findmin(root);
	printf("The min data is: %d", min->data);

	
 } 



void bst_insert(treepointer *node, int num)
{
	treepointer ptr, temp;
	temp = bst_modified_search(*node, num);
	
	if (temp || !(*node))
	{
		
		ptr = (treepointer)malloc(sizeof(*ptr));
		if (ptr == NULL)
		{
			printf("mem full");
			exit(1);
		}
		ptr->data = num;
		ptr->left_child = NULL, ptr->right_child = NULL;
		if (*node)
		{
			if (num > temp->data)
				temp->right_child = ptr;
			else
				temp->left_child = ptr;
		}
		else
			*node = ptr;
	}	
}



treepointer bst_modified_search(treepointer tree, int key)
{
	treepointer temp;
	if(!tree)
		return NULL;
	while (tree)
	{
		if (tree->data == key)
			return NULL;
		
		if (key > tree->data)
		{
			temp = tree;
			tree = tree->right_child;
		}
		else
		{
			temp = tree;
			tree = tree->left_child;
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

treepointer bst_findmin(treepointer tree_node)
{
	if (tree_node == NULL)
		return NULL;
	else if(tree_node->left_child != NULL)
		return bst_findmin(tree_node->left_child);
	return tree_node;
	
}



