#include <stdio.h>
#include <stdlib.h>

typedef struct node* treepointer;
struct node{
	int data;
	treepointer left_child, right_child;
};

void bst_insert(treepointer *node, int num);
treepointer bst_search_prev(treepointer tree, int key);
void inorder_print(treepointer ptr);
treepointer bst_findmin(treepointer tree_node);
treepointer bst_search(treepointer tree, int key);

void main()
{
	treepointer root = NULL, search_result= NULL, temp, min_node, tree_2;
	int number, i, data;
	
	printf("Enter the number of data item: ");
	scanf("%d", &number);
	
	for (i = 1; i <= number; i++)
	{
		printf("Enter the data item No.%d: ", i);
		scanf("%d", &data); 
		bst_insert(&root, data);
	}
	
	printf("Inorder traversal for the binary search tree:\n");
	inorder_print(root);
	min_node = bst_findmin(root);
	printf("min = %d", min_node->data);	
	
	printf("Enter number you want to search:\n");
	scanf("%d", &data);
	search_result = bst_search(root, data);
	if (search_result)
		printf("Found!");
	else
		printf("Not found!");
	
	
}


void bst_insert(treepointer *node, int num)
{
	treepointer temp, ptr;
	temp = bst_search_prev(*node, num);
	if (temp||!(*node))
	{
		ptr = (treepointer)malloc(sizeof(*temp));	
		if (ptr == NULL)
		{
			printf("memfull");
			exit(1);
		}
		ptr->data = num;
		ptr->left_child = NULL, ptr->right_child = NULL;
		
		if (*node)
		{
			
			if (ptr->data > temp->data)
				temp->right_child = ptr;
			else
				temp->left_child = ptr;
		}
		else
		{
			*node = ptr;
		}
	}	
}

treepointer bst_search_prev(treepointer tree, int key)
{
	treepointer temp;
	if (!tree)
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
			tree= tree->left_child;
		}
	}
	return temp;
}

treepointer bst_search(treepointer tree, int key)
{
	if (!tree)
		return NULL;
	while (tree)
	{
		if (tree->data == key)
			return tree;
		if (key > tree->data)
		{
			tree = tree->right_child;
		}
		else
		{
			tree= tree->left_child;
		}
	}
	return NULL;
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
	if (tree_node ==NULL)
		return NULL;
	if (tree_node->left_child != NULL)
		return bst_findmin(tree_node->left_child);
	return tree_node;
}
