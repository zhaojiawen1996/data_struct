#ifndef __LATIN_H__
#define __LATIN_H__

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

Status Creat_List(LinkedList *L);
Status Print_Square(LinkedList L);



#endif