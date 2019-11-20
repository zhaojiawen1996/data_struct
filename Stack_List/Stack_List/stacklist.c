/*
*********************************************************
* 文件名：stacklist.c
* 作  者：wenzi
* 日  期：2019/11/13
* 版  本：v1.0
*********************************************************
*/

#include "stacklist.h"
#include "stdio.h"

/*
****************************************************
* 函数名：SqStack_Init
* 功  能：初始化普通栈
* 形  参：SqStack *S：要初始化的栈
* 返回值：操作的状态
****************************************************
*/
Status SqStack_Init(SqStack *S)
{
	S->top = -1;
	return OK;
}

/*
****************************************************
* 函数名：SqStack_Push
* 功  能：往栈中压入新数据
* 形  参：SqStack *S：要压入数据的栈
          int value ：要压入的数据
* 返回值：操作的状态
****************************************************
*/
Status SqStack_Push(SqStack *S,int value)
{
	/*已经满栈，不能再继续插入元素*/
	if(S->top == MAXSIZE - 1)
	{
	    return ERROR;
	}
	S->top ++;
	S->data[S->top] = value;
	return OK;
}

/*
****************************************************
* 函数名：SqStack_Pop
* 功  能：从栈中弹出数据
* 形  参：SqStack *S：要弹出数据的栈
          int value ：存储弹出的数据
* 返回值：操作的状态
****************************************************
*/
Status SqStack_Pop(SqStack *S,int *value)
{
	/*说明是空栈，没有数据可以弹出*/
	if(S->top == -1)
	{
	    return ERROR;
	}
	*value = S->data[S->top];
	S->top --;
	return ERROR;
}

/*
****************************************************
* 函数名：Show_List
* 功  能：输出栈中的所有元素
* 形  参：SqStack S：已有的栈
* 返回值：操作的状态
****************************************************
*/
void Show_List(SqStack S)
{
    int i;
	if(S.top < 0)
	{
         printf("This Stack is empty\n");	    
	}
	printf("The Stack Element is:\n");
	for(i = 0;i <= S.top;i++)
	{
		printf("%d\n",S.data[i]);
	}
}

/*
****************************************************
* 函数名：Share_Stack_Init
* 功  能：初始化共享栈
* 形  参：ShStack *S：要初始化的共享栈
* 返回值：操作的状态
****************************************************
*/
Status Share_Stack_Init(ShStack *S)
{
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return OK;
}

/*
****************************************************
* 函数名：Share_Stack_Push
* 功  能：往共享栈中压入数据
* 形  参：ShStack *S：      要压入数据的共享栈
          SElemType value： 要压入的数据
		      int Stack_Num:    共享栈中栈的编号
* 返回值：操作的状态
****************************************************
*/
Status Share_Stack_Push(ShStack *S,SElemType value,int Stack_Num)
{
	if(S->top1 + 1 == S->top2)/*共享栈处于满栈状态*/
	{
	    return ERROR;
	}
	if(Stack_Num == 1)
	{
		S->data[++S->top1] = value;/*对于栈1来说，++S->top1后存入数值*/
	}
	else if(Stack_Num == 2)
	{
		S->data[--S->top2] = value;/*对于栈2来说，--S->top2后存入数值*/
	}
	else
	{
		printf("The Stack_num is ERROR\n");
		return ERROR;
	}
	return OK;

}

/*
****************************************************
* 函数名：Share_Stack_Pop
* 功  能：从共享栈中弹出数据
* 形  参：ShStack *S：      要弹出数据的共享栈
          SElemType value： 存储弹出的数据
		  int Stack_Num:    共享栈中栈的编号
* 返回值：操作的状态
****************************************************
*/
Status Share_Stack_Pop(ShStack *S,SElemType *value,int stack_num)
{
	if((S->top1 < 0) && (S->top2 > MAXSIZE - 1))/*栈1和栈2都处于空栈，没有数据可以弹出*/
	{
	    return ERROR;
	}
	if(stack_num == 1)
	{
		if(S->top1 < 0)/*栈1是空栈，无法pop数据*/
		{
		    return ERROR;
		}
		*value = S->data[S->top1 --];
	}
	else if(stack_num == 2)
	{
		if(S->top2 > MAXSIZE - 1)/*栈2是空栈，无法pop数据*/
		{
		    return ERROR;
		}
		*value = S->data[S->top2 ++];
	}
    else
	{
		printf("The Stack_num is ERROR\n");
		return ERROR;
	}
}

/*
****************************************************
* 函数名：Show_ShList
* 功  能：输出共享栈中的数据
* 形  参：ShStack S：      要输出数据的栈
* 返回值：操作的状态
****************************************************
*/
void Show_ShList(ShStack S)
{
	int i;
	printf("The Stack1's Element is:\n");
	for(i = 0;i <= S.top1;i ++)
	{
		printf("%d\n",S.data[i]);
	}
	printf("The Stack2's Element is:\n");
	for(i = MAXSIZE - 1;i >= S.top2;i --)
	{
		printf("%d\n",S.data[i]);
	}
}
