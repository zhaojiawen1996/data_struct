#ifndef __DOUBLE_LINKED_LIST_H__
#define __DOUBLE_LINKED_LIST_H__

typedef  unsigned char Status;
typedef  int           ElemType;

#define    OK       1
#define    ERROR    0

typedef struct Node
{
	ElemType data;
	struct Node *next;
	struct Node *prior;
}Node;

typedef struct Node *DuLinked_List;

Status Show_List(DuLinked_List L);
Status Creat_List_Tail(DuLinked_List *L,int length,int value);
Status Init_List(DuLinked_List *L);
Status Creat_List_Head(DuLinked_List *L,int length,int value);
Status Incert_List(DuLinked_List *L,int position,int value);
Status Delet_List(DuLinked_List *L,int position,int *value);
int Length_List(DuLinked_List L);



#endif