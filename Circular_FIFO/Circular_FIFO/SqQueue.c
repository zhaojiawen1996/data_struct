/*
*****************************************************
* �ļ�����SqQueue.c
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/20
* ��  ����v1.0
*****************************************************
*/

#include "SqQueue.h"
#include "stdio.h"

/*
************************************************
* ��������Queue_Init
* ��  �ܣ����г�ʼ��
* ��  �Σ�SqQueue_st *Queue��Ҫ���г�ʼ���Ķ���
* ����ֵ��OK or ERROR
*************************************************
*/
Status Queue_Init(SqQueue_st *Queue)
{
	Queue->front = 0;
	Queue->rear = 0;
	return OK;
}

/*
************************************************
* ��������Queue_Incert
* ��  �ܣ��������в�������
* ��  �Σ�SqQueue_st *Queue��Ҫ���г�ʼ���Ķ���
          SqElemType value�� Ҫ���������
* ����ֵ��OK or ERROR
*************************************************
*/
Status Queue_Incert(SqQueue_st *Queue,SqElemType value)
{
	if((Queue->rear + 1)%MAXSIZE == Queue->rear)
	{
	    return ERROR;/*�����������޷��ٴβ�������*/
	}
	Queue->data[Queue->rear] = value;
	Queue->rear = ((Queue->rear + 1)%MAXSIZE);/*βָ�������һλ�����Ƶ�β��ʱ���Ƶ�����ͷ��*/
	return OK;
}


/*
********************************************************
* ��������Queue_Out
* ��  �ܣ��Ӷ�����ȡ��һ������
* ��  �Σ�SqQueue_st *Queue��Ҫ���в����Ķ���
          SqElemType *value:���ڱ���Ӷ�����ȡ��������
* ����ֵ��OK or ERROR
*******************************************************
*/
Status Queue_Out(SqQueue_st *Queue,SqElemType *value)
{
	if(Queue->front == Queue->rear)
	{
	    return ERROR;/*����Ϊ�գ��޷���ȡ������*/
	}
	*value = Queue->data[Queue->front];/*�����ȳ����Ӷ���ͷȡ��һ��Ԫ��*/
	Queue->front = ((Queue->front + 1)%MAXSIZE);/*ͷָ���������һλ�����Ƶ�β��ʱ���Ƶ�����ͷ��*/
	return OK;
}


/*
********************************************************
* ��������Queue_Length
* ��  �ܣ��������֪���еĳ���
* ��  �Σ�SqQueue_st Queue��Ҫ���в����Ķ���
* ����ֵ��length
*******************************************************
*/
int Queue_Length(SqQueue_st Queue)
{
    int length;
	length = (Queue.rear - Queue.front + MAXSIZE)%MAXSIZE;
	return length;
}

/*
********************************************************
* ��������Queue_Print
* ��  ��: ����֪�������������
* ��  �Σ�SqQueue_st Queue��Ҫ���в����Ķ���
* ����ֵ��OK or ERROR
*******************************************************
*/
Status Queue_Print(SqQueue_st Queue)
{
	if(Queue.front == Queue.rear)
	{
	     return ERROR;/*�ն���*/
	}
	while(Queue.front != Queue.rear)
	{
		printf("%d\n",Queue.data[Queue.front]);
		Queue.front = (Queue.front + 1)%MAXSIZE;
	}
}