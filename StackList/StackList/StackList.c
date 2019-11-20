/*
***************************************************
* �ļ�����StackList.c
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/14
* ��  ����v1.0
***************************************************
*/


#include "StackList.h"
#include "stdlib.h"
#include "stdio.h"

/*
***************************************************
* ��������Stack_Link_Init
* ��  �ܣ���ʼ����ջ��ջ����ʼ��Ϊ��
* ��  �Σ�StackLink *S��Ҫ���в�������ջ
* ����ֵ������״̬
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
* ��������Stack_Link_Push
* ��  �ܣ�����ջ��ѹ��һ��Ԫ��
* ��  �Σ�StackLink *S��  Ҫ���в�������ջ
          SElemType value ��ѹ�����ֵ
* ����ֵ������״̬
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
* ��������Stack_Link_Pop
* ��  �ܣ�����ջ�е���һ��Ԫ��
* ��  �Σ�StackLink *S��  Ҫ���в�������ջ
          SElemType *value ���洢��������ֵ
* ����ֵ������״̬
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
* ��������Show_Stack_List
* ��  �ܣ�����ջ��������е�Ԫ��
* ��  �Σ�StackLink *S��  Ҫ���в�������ջ
* ����ֵ������״̬
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

