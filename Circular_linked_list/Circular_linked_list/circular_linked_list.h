#ifndef __CIRCULAR_LINKED_LIST__
#define __CIRCULAR_LINKED_LIST__

#define OK          1
#define ERROR       0


typedef unsigned char Status;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
	struct Node *next;
}Node;

typedef struct Node *LinkedList;

Status Show_List(LinkedList L);
Status Creat_Circular_list_head(LinkedList *L,int length);
Status Creat_Circular_list_Tail(LinkedList *L,int length);



#endif