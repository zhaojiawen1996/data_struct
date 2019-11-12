#include "Double_Linked_List.h"
#include "stdio.h"
#include "stdlib.h"

DuLinked_List L;

int main(void)
{
	int value = 4;
	int length;
    Init_List(&L);
	Creat_List_Tail(&L,5,value);
	Show_List(L);
	Init_List(&L);
	Creat_List_Head(&L,5,value);
	Show_List(L);
	Incert_List(&L,2,value);
	Show_List(L);
	Delet_List(&L,2,&value);
	Show_List(L);
	length = Length_List(L);
	printf("The Length of the List is:\n");
	printf("%d\nX",length);
}