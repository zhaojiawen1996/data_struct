#ifndef __MAGICIAN_H__
#define __MAGICIAN_H__

typedef unsigned char Status;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
	struct Node *next;
}sqlist,*Linked_List;

typedef struct 
{
	Linked_List head;
	int count;
}LinkedList;

#define     OK       1
#define     ERROR    0

#if 0
Status Print_List(LinkedList L);
#else
Status Creat_List(LinkedList *L);
#endif
Status Print_List(LinkedList L);
Status Creat_Cards_Order(LinkedList *L);

#endif