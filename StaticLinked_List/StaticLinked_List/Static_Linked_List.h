#ifndef __STATIC_LINKED_LIST_H__
#define __STATIC_LINKED_LIST_H__

#include "Static_Linked_List.h"

typedef int ElemType;
typedef unsigned char Status;

#define    OK       1
#define    ERROR    0

#define MAXSIZE 100

typedef struct
{
    ElemType data;
	int cur;/*数组的游标*/
}component,StaticLink[MAXSIZE];


Status	InitLink(StaticLink L);

#if 1
int MALLOC_SLL(StaticLink L);
int Creat_Static_List(StaticLink L,int length,int value);
#else 
int MALLOC_SLL(component L);
int Creat_Static_List(component *L,int length,int value);
#endif
int Length_StaticLink(StaticLink L);
void Print_Static_Link(StaticLink L);
int Incert_StaticList(StaticLink L, ElemType value, int position);

#endif