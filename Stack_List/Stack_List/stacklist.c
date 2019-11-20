/*
*********************************************************
* �ļ�����stacklist.c
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/13
* ��  ����v1.0
*********************************************************
*/

#include "stacklist.h"
#include "stdio.h"

/*
****************************************************
* ��������SqStack_Init
* ��  �ܣ���ʼ����ͨջ
* ��  �Σ�SqStack *S��Ҫ��ʼ����ջ
* ����ֵ��������״̬
****************************************************
*/
Status SqStack_Init(SqStack *S)
{
	S->top = -1;
	return OK;
}

/*
****************************************************
* ��������SqStack_Push
* ��  �ܣ���ջ��ѹ��������
* ��  �Σ�SqStack *S��Ҫѹ�����ݵ�ջ
          int value ��Ҫѹ�������
* ����ֵ��������״̬
****************************************************
*/
Status SqStack_Push(SqStack *S,int value)
{
	/*�Ѿ���ջ�������ټ�������Ԫ��*/
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
* ��������SqStack_Pop
* ��  �ܣ���ջ�е�������
* ��  �Σ�SqStack *S��Ҫ�������ݵ�ջ
          int value ���洢����������
* ����ֵ��������״̬
****************************************************
*/
Status SqStack_Pop(SqStack *S,int *value)
{
	/*˵���ǿ�ջ��û�����ݿ��Ե���*/
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
* ��������Show_List
* ��  �ܣ����ջ�е�����Ԫ��
* ��  �Σ�SqStack S�����е�ջ
* ����ֵ��������״̬
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
* ��������Share_Stack_Init
* ��  �ܣ���ʼ������ջ
* ��  �Σ�ShStack *S��Ҫ��ʼ���Ĺ���ջ
* ����ֵ��������״̬
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
* ��������Share_Stack_Push
* ��  �ܣ�������ջ��ѹ������
* ��  �Σ�ShStack *S��      Ҫѹ�����ݵĹ���ջ
          SElemType value�� Ҫѹ�������
		      int Stack_Num:    ����ջ��ջ�ı��
* ����ֵ��������״̬
****************************************************
*/
Status Share_Stack_Push(ShStack *S,SElemType value,int Stack_Num)
{
	if(S->top1 + 1 == S->top2)/*����ջ������ջ״̬*/
	{
	    return ERROR;
	}
	if(Stack_Num == 1)
	{
		S->data[++S->top1] = value;/*����ջ1��˵��++S->top1�������ֵ*/
	}
	else if(Stack_Num == 2)
	{
		S->data[--S->top2] = value;/*����ջ2��˵��--S->top2�������ֵ*/
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
* ��������Share_Stack_Pop
* ��  �ܣ��ӹ���ջ�е�������
* ��  �Σ�ShStack *S��      Ҫ�������ݵĹ���ջ
          SElemType value�� �洢����������
		  int Stack_Num:    ����ջ��ջ�ı��
* ����ֵ��������״̬
****************************************************
*/
Status Share_Stack_Pop(ShStack *S,SElemType *value,int stack_num)
{
	if((S->top1 < 0) && (S->top2 > MAXSIZE - 1))/*ջ1��ջ2�����ڿ�ջ��û�����ݿ��Ե���*/
	{
	    return ERROR;
	}
	if(stack_num == 1)
	{
		if(S->top1 < 0)/*ջ1�ǿ�ջ���޷�pop����*/
		{
		    return ERROR;
		}
		*value = S->data[S->top1 --];
	}
	else if(stack_num == 2)
	{
		if(S->top2 > MAXSIZE - 1)/*ջ2�ǿ�ջ���޷�pop����*/
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
* ��������Show_ShList
* ��  �ܣ��������ջ�е�����
* ��  �Σ�ShStack S��      Ҫ������ݵ�ջ
* ����ֵ��������״̬
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
