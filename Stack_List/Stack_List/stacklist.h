#ifndef __STACKLIST_H__
#define __STACKLIST_H__

typedef int             SElemType;/*���Ͳ��̶�*/
typedef unsigned char   Status;


#define MAXSIZE  20

#define      OK      1
#define      ERROR   0



typedef struct 
{
	SElemType data[MAXSIZE];
	int top;/*����ջ��ָ��*/
}SqStack;

typedef struct
{
  SElemType data[MAXSIZE];
	int top1;/*����ջ1��ջ��ָ��*/
	int top2;/*����ջ2��ջ��ָ��*/
}ShStack;

/*��ͨջ��غ���*/
Status SqStack_Init(SqStack *S);
Status SqStack_Push(SqStack *S,int value);
Status SqStack_Pop(SqStack *S,int *value);
void Show_List(SqStack S);

/*����ջ��غ���*/
Status Share_Stack_Init(ShStack *S);
Status Share_Stack_Push(ShStack *S,SElemType value,int Stack_Num);
Status Share_Stack_Pop(ShStack *S,SElemType *value,int stack_num);
void Show_ShList(ShStack S);

#endif
