#include "Static_Linked_List.h"
#include "stdio.h"

#if 0
component L[MAXSIZE];
#else 
StaticLink L;
#endif

int main(void)
{
	int value = 5;
	int i;
	int Subcript;
	int length;
	InitLink(L);
	Subcript = Creat_Static_List(L,5,value);
	length = Length_StaticLink(L);
	printf("The length of static linked_list is:%d\n",length);
	printf("The Subcript is:%d\n",Subcript);
	printf("The Static List is:\n");
	Incert_StaticList(L,value,2);
	Print_Static_Link(L);
}