#ifndef __MIDDLE_POINTER_H__
#define __MIDDLE_POINTER_H__

typedef int ElemType;
typedef unsigned char Status;

typedef struct Node
{
    ElemType data;
	struct Node *next;
}Node;

typedef struct	Node *Linked_List;

#define     OK       1
#define     ERROR    0

void Print_List(Linked_List L);
Status Incert_Tail(Linked_List* L,int count);
Status Middle_Pointer(Linked_List L,int *value);

#endif