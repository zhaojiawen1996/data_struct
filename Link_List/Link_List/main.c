#include "link_list.h"
#include "stdio.h"
#include "stdlib.h"



int main(void)
{
	Linklist L;
	ElemType value;
#if 0
	Node L;
	//L = (Node *)malloc(sizeof(Node));
	Creat_List_Head(&L,5);
	Show_List(&L);
#else 
	Creat_List_Head(&L,5);
	GetElem(L,2,&value);
	Show_List(&L);
	Creat_List_Tail(&L,5);
	Show_List(&L);
	ListIncert(&L, 1, 9);
	Show_List(&L);
	ListDelet(&L,1,&value);
	Show_List(&L);
	ClearList(&L);
	Show_List(&L);

#endif

}