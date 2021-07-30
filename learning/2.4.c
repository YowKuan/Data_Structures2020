#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

struct date{
	int day;
	int month;
	int year;
};
struct person{
	char name[10];
	char mail[10];
	int age;
	struct date dob;
};

typedef struct{
	int sex;
	union {
		int children;
		int beard;
	}u;
}sex_type;

int HumanEqual(struct person p1, struct person p2 );

void main()
{
	struct person p1, p2;
	p1.age=30;
	strcpy(p1.name, "Tom");
	p1.dob.day = 20 ;
	p1.dob.month = 12 ;
	p1.dob.year = 1997;
	strcpy(p1.mail, "google.com");
	
	p2.age=30;
	strcpy(p2.name, "Mary");
	strcpy(p2.mail, "yahoo.com");
	p2.dob.day = 1 ;
	p2.dob.month = 2 ;
	p2.dob.year = 1998;
	
	if (HumanEqual(p1, p2))
		printf("The Same.\n");
	else 
		printf("Not the same.\n");
	
}
int HumanEqual(struct person p1, struct person p2){
	if (p1.age != p2.age)
		return FALSE;
	return TRUE;
	
}

