#include <stdio.h>
#include <stdlib.h>

typedef struct node* tree_pointer;
struct node {
	int data;
    tree_pointer left_child, right_child;
};
void Binary_Search_Tree_Insert_Node(tree_pointer *node, int num);
tree_pointer Binary_Search_Tree_Modified_Search(tree_pointer tree, int key);
void Tree_Inorder(tree_pointer ptr);
tree_pointer Binary_Search_Tree_Recursive_Search(tree_pointer root, int key);
tree_pointer Binary_Tree_Copy(tree_pointer Original);
int Binary_Tree_Equal(tree_pointer first, tree_pointer second);
tree_pointer Binary_Search_Tree_Find_Minimum(tree_pointer tree_node);
tree_pointer Binary_Search_Tree_Delete(tree_pointer root, int x);

void main()
{
	tree_pointer root = NULL, temp, min_node, tree_2;
	int number, i, data;
	
	printf("Enter the number of data item: ");
	scanf("%d", &number);
	
	for (i = 1; i <= number; i++)
	{
		printf("Enter the data item No.%d: ", i);
		scanf("%d", &data); 
		Binary_Search_Tree_Insert_Node(&root, data);
	}
	
	printf("Inorder traversal for the binary search tree:\n");
	Tree_Inorder(root);	
	/*
	while (1) // infinit loop for testing insert
	{
		printf("\nInsert again: ");
		scanf("%d", &data); 
		Binary_Search_Tree_Insert_Node(&root, data);
		printf("Inorder traversal for the binary search tree:\n");
		Tree_Inorder(root);
	}*/
	printf("\n");
	
	min_node = Binary_Search_Tree_Find_Minimum(root);
	printf("Min = %d", min_node->data);
		
	while(1)
	{
		printf("\nEnter the data to be deleted: ");
		scanf("%d", &data); 
		if (root)	
		{
			root = Binary_Search_Tree_Delete(root, data);
			Tree_Inorder(root);
		}
		else
		{
			printf("Empty tree!\n");
			break;
		}
	}
	
	while (1) // infinit loop for testing search
	{
		printf("Enter the data to search in the binary search tree: ");
		scanf("%d", &data); 
		temp = Binary_Search_Tree_Recursive_Search(root, data);
		if (!temp)
			printf("Not found!\n");
		else
			printf("Found!\n");
	}
	
	// Copy
	tree_2 = Binary_Tree_Copy(root);
	Tree_Inorder(tree_2);
	printf("\n");
	if(Binary_Tree_Equal(root, tree_2))
		printf("Equal!\n");
	else
		printf("Unequal!\n");
		
	printf("\nInsert again: ");
	scanf("%d", &data); 
	Binary_Search_Tree_Insert_Node(&tree_2, data);	
	Tree_Inorder(tree_2);
	printf("\n");	
	if(Binary_Tree_Equal(root, tree_2))
		printf("Equal!\n");
	else
		printf("Unequal!\n");	

}

void Binary_Search_Tree_Insert_Node(tree_pointer *node, int num)
{
    /* If num is in the tree pointed at by node do nothing;             otherwise add a new node with data=num */
	tree_pointer ptr;
	tree_pointer temp = Binary_Search_Tree_Modified_Search(*node, num);
    if (temp || !(*node)) 
	{  /* num is not in the tree */            
		ptr = (tree_pointer)malloc(sizeof(*ptr));
		if (ptr == NULL)
		{
			printf("Out of memory!\n");
			exit(1);
		}
        ptr->data = num;
        ptr->left_child = ptr->right_child = NULL;
        if (*node) /* insert as child of temp */
        {
        	if (num < temp->data) 
				temp->left_child = ptr;
			else 
				temp->right_child = ptr;
		}
        else 
			*node = ptr; /* insert as root */
    }
}

tree_pointer Binary_Search_Tree_Modified_Search(tree_pointer tree, int key)
{
	tree_pointer temp;
	
	if (!tree) /* tree is empty */
		return NULL; 
		
	while (tree) 
	{           
		if (key == tree->data) /* if found, return NULL (cannot be inserted) */
			return NULL;          
		if (key < tree->data)
		{
			temp = tree;
			tree = tree->left_child;
		}
		else  
		{
			temp = tree;              
			tree = tree->right_child;    
		}
	}     
	
	return temp;
}

void Tree_Inorder(tree_pointer ptr)
{    /* inorder tree traversal */    
	if (ptr) 
	{           
		Tree_Inorder(ptr->left_child);           
		printf(" %d", ptr->data);           
		Tree_Inorder(ptr->right_child);     
	}  
}

tree_pointer Binary_Search_Tree_Recursive_Search(tree_pointer root, int key)
{     /* return a pointer to the node that contains key, if 
       there is no such node, return NULL. */     
	if (!root) 
		return NULL;
	if (key == root->data)
		return root;
	if (key < root->data)         
		return Binary_Search_Tree_Recursive_Search(root->left_child, key);    
	return Binary_Search_Tree_Recursive_Search(root->right_child, key);
}

tree_pointer Binary_Tree_Copy(tree_pointer Original)
{
    /* this function returns a tree_pointer to an exact copy of
	   the original tree */    
	tree_pointer temp;
	
	if (Original)
	{
		temp = (tree_pointer)malloc(sizeof(*temp));
		if(temp == NULL)
		{                
			printf("Out of memory\n");
			exit(1);           
		}
		temp->left_child = Binary_Tree_Copy(Original->left_child); 
		temp->right_child = Binary_Tree_Copy(Original->right_child);
		temp->data = Original->data;
		
		return temp;
	}    
	else
		return NULL;
}

int Binary_Tree_Equal(tree_pointer first, tree_pointer second)
{
   /* function returns FALSE if the binary trees first and
      second are not equal, Otherwise it returns TRUE */    
	return ((!first && !second) || (first && second && 
	        first->data == second->data) &&
			Binary_Tree_Equal(first->left_child, second->left_child) 
			&& Binary_Tree_Equal(first->right_child, second->right_child));
}

tree_pointer Binary_Search_Tree_Find_Minimum(tree_pointer tree_node)
{
    if(tree_node == NULL)
    	return NULL;
    else if(tree_node->left_child != NULL) // node with minimum value will have no left child
    	return Binary_Search_Tree_Find_Minimum(tree_node->left_child); // left most element will be minimum
    return tree_node;
}

tree_pointer Binary_Search_Tree_Delete(tree_pointer root, int x)
{
    //searching for the item to be deleted
    if(root == NULL)
        return NULL;
    if (x > root->data)
        root->right_child = Binary_Search_Tree_Delete(root->right_child, x);
    else if(x < root->data)
        root->left_child = Binary_Search_Tree_Delete(root->left_child, x);
    else
    {   //No Children
    	if(root->left_child == NULL && root->right_child == NULL)
        {
        	free(root);
            return NULL;
        }
        //One Child
        else if(root->left_child == NULL || root->right_child == NULL)
        {
            tree_pointer temp;
            if(root->left_child == NULL)
            	temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            
			return temp;
        }
        //Two Children
        else
        {
            tree_pointer temp = Binary_Search_Tree_Find_Minimum(root->right_child);
            root->data = temp->data;
            root->right_child = Binary_Search_Tree_Delete(root->right_child, temp->data);
        }
    }
    return root;
}
