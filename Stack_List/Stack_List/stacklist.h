#ifndef __STACKLIST_H__
#define __STACKLIST_H__

typedef int             SElemType;/*类型不固定*/
typedef unsigned char   Status;


#define MAXSIZE  20

#define      OK      1
#define      ERROR   0



typedef struct 
{
	SElemType data[MAXSIZE];
	int top;/*用于栈顶指针*/
}SqStack;

typedef struct
{
  SElemType data[MAXSIZE];
	int top1;/*用于栈1的栈顶指针*/
	int top2;/*用于栈2的栈顶指针*/
}ShStack;

/*普通栈相关函数*/
Status SqStack_Init(SqStack *S);
Status SqStack_Push(SqStack *S,int value);
Status SqStack_Pop(SqStack *S,int *value);
void Show_List(SqStack S);

/*共享栈相关函数*/
Status Share_Stack_Init(ShStack *S);
Status Share_Stack_Push(ShStack *S,SElemType value,int Stack_Num);
Status Share_Stack_Pop(ShStack *S,SElemType *value,int stack_num);
void Show_ShList(ShStack S);

#endif
