#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node *link;
}list;  

void main()
{
	list item1, item2, item3;
	list i;
	
	item1.data = 'a';
	item2.data = 'b';
	item3.data = 'c';
	
	item1.link = &item2;
	item2.link = &item3;
	item3.link = NULL;
	
	for (i = item1; i.link != NULL ; i = *(i.link))
{
	printf("%2c", i.data);
		if ((*(i.link)).link == NULL)
			printf("%2c", (*(i.link)).data);

		
	}
	
}
