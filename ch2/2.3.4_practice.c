#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int key;
	struct node *link;
}list;

void main(){
	list a1, a2, a3;
	list i;
	
	a1.key = 300000;
	a1.link = &a2;
	a2.key = 50000000;
	a2.link = &a3;
	a3.key = 8;
	a3.link = NULL;
	
	for (i = a1; i.link != NULL; i = *(i.link))
	{
		printf("%d ", i.key);
		if((*(i.link)).link == NULL)
		{
			printf("%d", (*(i.link)).key);
		} 
	}
	
	
} 
