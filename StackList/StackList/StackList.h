#ifndef __STACKLIST_H__
#define __STACKLIST_H__

typedef int  SElemType;
typedef unsigned char Status;

#define OK        1
#define ERROR     0 

/*定义链栈的结点*/
typedef struct SNode
{
  SElemType data;
	struct SNode *next;
}SNode;

typedef struct SNode *LinkSNode;

/*定义链栈的栈顶和链栈中元素的个数*/
typedef struct 
{
  LinkSNode top;
	int count;
}StackLink;

Status Stack_Link_Push(StackLink *S,SElemType value);
Status Stack_Link_Init(StackLink *S);
Status Stack_Link_Pop(StackLink *S,SElemType *value);
Status Show_Stack_List(StackLink S);

#endif
