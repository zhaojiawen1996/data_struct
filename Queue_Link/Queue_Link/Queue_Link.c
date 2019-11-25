/*
*************************************************************
* �ļ�����Queue_Link.c
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/25
* ��  ����V1.0
************************************************************
*/


#include "Queue_Link.h"
#include "stdio.h"
#include "stdlib.h"

/*
*************************************************************
* ��������Queue_Link_Init
* ��  �ܣ���ʼ��һ������
* ��  �Σ�QueueLink Q:
* ����ֵ��OK or ERROR
*************************************************************
*/
Status Queue_Link_Init(QueueLink *Q)
{
    Queue_Ptr P;
	P = (Queue_Ptr)malloc(sizeof(QNode));/*Ϊͷ�������ڴ�*/
	Q->front = (Queue_Ptr)malloc(sizeof(QNode));
	Q->rear = (Queue_Ptr)malloc(sizeof(QNode));/*Ϊͷָ���βָ�����洢�ռ�*/

	if(P == NULL || Q->front == NULL || Q->rear == NULL)
	{
	    printf("malloc fail!!!");
		return OK;
	}

	P->next = NULL;
	Q->front = P;
	Q->rear = P;
	Q->count = 0;
	return OK;
}

/*
*************************************************************
* ��������Queue_Link_Incert
* ��  �ܣ��������в���һ����Ԫ��
* ��  �Σ�QElemType value��Ҫ���������
* ����ֵ��OK or ERROR
*************************************************************
*/
Status Queue_Link_Incert(QueueLink *Q,QElemType value)
{
    Queue_Ptr P,L;
	P = (Queue_Ptr)malloc(sizeof(QNode));
	L = (Queue_Ptr)malloc(sizeof(QNode));
	if(P == NULL || L == NULL)
	{
	    printf("malloc fail\n");
		return ERROR;
	}
	P->data = value;
	P->next = NULL;
	L = Q->rear;
	L->next = P;
	Q->rear = P;/*����ǰ��βָ��ָ���½��*/
	Q->count ++;/*ÿ����һ��Ԫ�أ�countֵ++*/
    return OK;
}

/*
***********************************************************
* ��������Queue_Delet
* ��  �ܣ��Ӷ�����ɾ��һ��Ԫ��
* ��  �Σ�QueueLink *Q��   Ҫ����ɾ�������Ķ���
          QElemType *value:Ҫ����ɾ����Ԫ�� 
* ����ֵ��OK or ERROR
***********************************************************
*/
Status Queue_Delet(QueueLink *Q,QElemType *value)
{
	Queue_Ptr P;
    P = (Queue_Ptr)malloc(sizeof(QNode));
	if(Q->front == Q->rear)
	{
	    printf("The Queue is Empty!\n");
		return ERROR;
	}
	P = Q->front->next;
	*value = P->data;
	Q->front->next = P->next;
	if(P == Q->rear)
	{
		Q->rear = Q->front;
	}
	free(P);
#if 0/*��һ�ַ�������ͷָ���ֻ��һ��Ԫ�ص����*/
	if(Q->count == 1)
	{
		Q->rear = Q->front;
	}
#endif
	Q->count --;
	return OK;
}

/*
***************************************************
* ��������Queue_Print
* ��  ��:��������е�����Ԫ��
* ��  �Σ�QueueLink Q�����ڵĶ���
* ����ֵ��OK or ERROR
***************************************************
*/
Status Queue_Print(QueueLink Q)
{
	Queue_Ptr P;
	P = (Queue_Ptr)malloc(sizeof(QNode));
	P = Q.front;
	if(P == Q.rear)
	{
		printf("The Queue is Empty\n");
	    return ERROR;
	}
	printf("The Queue Element is:\n");
	while(P != Q.rear)
	{
		P = P->next;
		printf("%d\n",P->data);
	}
	return OK;
}