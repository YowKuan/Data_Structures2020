#include <stdio.h>
#include <stdlib.h>

typedef struct node* tree_pointer;
struct node{
	int data;
	tree_pointer left_child, right_child;
};

void binary_search_tree_insert(tree_pointer *node, int num);
tree_pointer binary_search_modified_search(tree_pointer tree, int key);
tree_pointer recursive_search(tree_pointer root, int key);
void tree_inorder(tree_pointer ptr);

void main()
{	
	tree_pointer root;
	int i, num, data;
	printf("Enter number added into bst:\n");
	scanf("%d", &num);
	
	for (i = 1; i <= num; i++)
	{
		printf("Enter number %d: ", i);
		scanf("%d", &data);
		binary_search_tree_insert(&root, data);
	}
	printf("The inorder result is:\n");
	tree_inorder(root);
}


void binary_search_tree_insert(tree_pointer *node, int num)
{
	tree_pointer ptr;
	tree_pointer temp = binary_search_modified_search(*node, num);
	//difficult...
	if((temp)||!(*node))
	{
		ptr = (tree_pointer)malloc(sizeof(*ptr));
		if (ptr == NULL)
		{
			printf("memory full");
			exit(1);
		}
		ptr->data = num;
		ptr->left_child = NULL, ptr->right_child = NULL;
		
		if (*node)
		{
			if (num < temp->data)
			{
				temp->left_child = ptr;
			}
			else
			{
				temp->right_child = ptr;
			}
		}
		else
			*node = ptr;
		
	}
}


tree_pointer binary_search_modified_search(tree_pointer tree, int key)
{
	tree_pointer temp;
	
	if (!tree)
	{
		return NULL;
	}
	while (tree)
	{
		if (key == tree->data)
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

void tree_inorder(tree_pointer ptr)
{
	if (ptr)
	{
		tree_inorder(ptr->left_child);
		printf("%d ", ptr->data);
		tree_inorder(ptr->right_child);
	}
}

//treepointer recursive_search(tree_pointer root, int key)
//{
//	if (!root)
//		return NULL;
//	if (key == root->data)
//		return root;
//}
