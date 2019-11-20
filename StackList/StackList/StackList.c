/*
***************************************************
* 文件名：StackList.c
* 作  者：wenzi
* 日  期：2019/11/14
* 版  本：v1.0
***************************************************
*/


#include "StackList.h"
#include "stdlib.h"
#include "stdio.h"

/*
***************************************************
* 函数名：Stack_Link_Init
* 功  能：初始化链栈，栈顶初始化为空
* 形  参：StackLink *S：要进行操作的链栈
* 返回值：操作状态
**************************************************
*/
Status Stack_Link_Init(StackLink *S)
{
	S->top = (LinkSNode)malloc(sizeof(SNode));
	S->top = NULL;
	S->count = 0;
	return OK;
}

/*
***************************************************
* 函数名：Stack_Link_Push
* 功  能：往链栈中压入一个元素
* 形  参：StackLink *S：  要进行操作的链栈
          SElemType value ：压入的数值
* 返回值：操作状态
**************************************************
*/
Status Stack_Link_Push(StackLink *S,SElemType value)
{
  LinkSNode P;
	P = (LinkSNode)malloc(sizeof(SNode));
	P->data = value;
	P->next = S->top;
	S->top = P;
	return OK;
}


/*
***************************************************
* 函数名：Stack_Link_Pop
* 功  能：从链栈中弹出一个元素
* 形  参：StackLink *S：  要进行操作的链栈
          SElemType *value ：存储弹出的数值
* 返回值：操作状态
**************************************************
*/
Status Stack_Link_Pop(StackLink *S,SElemType *value)
{
	LinkSNode P;
	P = (LinkSNode)malloc(sizeof(SNode)); 
	if(!S->top)
	{
	    return ERROR;
	}
	P = S->top;
	*value = S->top->data;
	S->top = P->next;
	S->count --;
	free(P);
	return OK;
}


/*
***************************************************
* 函数名：Show_Stack_List
* 功  能：从链栈中输出已有的元素
* 形  参：StackLink *S：  要进行操作的链栈
* 返回值：操作状态
**************************************************
*/
Status Show_Stack_List(StackLink S)
{
  LinkSNode P;
	P = S.top;
	printf("The StackLink Element is :\n");
	while(P != NULL)
	{
		printf("%d\n",P->data);
		P = P->next;
	}
	return OK;
}

