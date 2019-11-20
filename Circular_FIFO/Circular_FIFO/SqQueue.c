/*
*****************************************************
* 文件名：SqQueue.c
* 作  者：wenzi
* 日  期：2019/11/20
* 版  本：v1.0
*****************************************************
*/

#include "SqQueue.h"
#include "stdio.h"

/*
************************************************
* 函数名：Queue_Init
* 功  能：队列初始化
* 形  参：SqQueue_st *Queue：要进行初始化的队列
* 返回值：OK or ERROR
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
* 函数名：Queue_Incert
* 功  能：往队列中插入数据
* 形  参：SqQueue_st *Queue：要进行初始化的队列
          SqElemType value： 要插入的数据
* 返回值：OK or ERROR
*************************************************
*/
Status Queue_Incert(SqQueue_st *Queue,SqElemType value)
{
	if((Queue->rear + 1)%MAXSIZE == Queue->rear)
	{
	    return ERROR;/*队列已满，无法再次插入数据*/
	}
	Queue->data[Queue->rear] = value;
	Queue->rear = ((Queue->rear + 1)%MAXSIZE);/*尾指针向后移一位，当移到尾部时，移到队列头部*/
	return OK;
}


/*
********************************************************
* 函数名：Queue_Out
* 功  能：从队列中取出一个数据
* 形  参：SqQueue_st *Queue：要进行操作的队列
          SqElemType *value:用于保存从队列中取出的数据
* 返回值：OK or ERROR
*******************************************************
*/
Status Queue_Out(SqQueue_st *Queue,SqElemType *value)
{
	if(Queue->front == Queue->rear)
	{
	    return ERROR;/*队列为空，无法获取到数据*/
	}
	*value = Queue->data[Queue->front];/*先入先出，从队列头取出一个元素*/
	Queue->front = ((Queue->front + 1)%MAXSIZE);/*头指针针向后移一位，当移到尾部时，移到队列头部*/
	return OK;
}


/*
********************************************************
* 函数名：Queue_Length
* 功  能：计算出已知队列的长度
* 形  参：SqQueue_st Queue：要进行操作的队列
* 返回值：length
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
* 函数名：Queue_Print
* 功  能: 从已知队列中输出数据
* 形  参：SqQueue_st Queue：要进行操作的队列
* 返回值：OK or ERROR
*******************************************************
*/
Status Queue_Print(SqQueue_st Queue)
{
	if(Queue.front == Queue.rear)
	{
	     return ERROR;/*空队列*/
	}
	while(Queue.front != Queue.rear)
	{
		printf("%d\n",Queue.data[Queue.front]);
		Queue.front = (Queue.front + 1)%MAXSIZE;
	}
}