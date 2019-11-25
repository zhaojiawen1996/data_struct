/*
*************************************************************
* 文件名：Queue_Link.c
* 作  者：wenzi
* 日  期：2019/11/25
* 版  本：V1.0
************************************************************
*/


#include "Queue_Link.h"
#include "stdio.h"
#include "stdlib.h"

/*
*************************************************************
* 函数名：Queue_Link_Init
* 功  能：初始化一个队列
* 形  参：QueueLink Q:
* 返回值：OK or ERROR
*************************************************************
*/
Status Queue_Link_Init(QueueLink *Q)
{
    Queue_Ptr P;
	P = (Queue_Ptr)malloc(sizeof(QNode));/*为头结点分配内存*/
	Q->front = (Queue_Ptr)malloc(sizeof(QNode));
	Q->rear = (Queue_Ptr)malloc(sizeof(QNode));/*为头指针和尾指针分配存储空间*/

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
* 函数名：Queue_Link_Incert
* 功  能：往队列中插入一个新元素
* 形  参：QElemType value：要插入的数据
* 返回值：OK or ERROR
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
	Q->rear = P;/*将当前的尾指针指向新结点*/
	Q->count ++;/*每插入一个元素，count值++*/
    return OK;
}

/*
***********************************************************
* 函数名：Queue_Delet
* 功  能：从队列中删除一个元素
* 形  参：QueueLink *Q：   要进行删除操作的队列
          QElemType *value:要保存删除的元素 
* 返回值：OK or ERROR
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
#if 0/*第一种方法处理头指针后只有一个元素的情况*/
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
* 函数名：Queue_Print
* 功  能:输出队列中的所有元素
* 形  参：QueueLink Q：现在的队列
* 返回值：OK or ERROR
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