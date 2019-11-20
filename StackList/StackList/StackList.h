#ifndef __STACKLIST_H__
#define __STACKLIST_H__

typedef int  SElemType;
typedef unsigned char Status;

#define OK        1
#define ERROR     0 

/*������ջ�Ľ��*/
typedef struct SNode
{
  SElemType data;
	struct SNode *next;
}SNode;

typedef struct SNode *LinkSNode;

/*������ջ��ջ������ջ��Ԫ�صĸ���*/
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
