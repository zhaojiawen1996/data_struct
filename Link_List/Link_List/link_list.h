#ifndef __LINK_LIST_H__
#define __LINK_LIST_H__

typedef int ElemType;
typedef unsigned char Status;

#define ERROR     0
#define OK        1

#define TRUE      1
#define FALSE     0

typedef struct Node
{
    ElemType data;
	struct Node *next;
}Node;

typedef struct Node *Linklist;

typedef struct Node Link;

Status GetElem(Linklist L,int position,ElemType *value);
#if 1
Status Creat_List_Head(Linklist *L,int n);
Status Creat_List_Tail(Linklist *L, int n);
#else 
Status Creat_List_Head(Node *L,int n);
#endif

Status ListIncert(Linklist *L, int position, ElemType value);
Status ListDelet(Linklist *L, int position, ElemType *value);
Status ClearList(Linklist *L);

#if 1
void Show_List(Linklist *L);
#else
void Show_List(Node *L);
#endif

#endif