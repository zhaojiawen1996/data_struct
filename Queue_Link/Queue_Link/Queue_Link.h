/*
*************************************************************
* 文件名：Queue_Link.c
* 作  者：wenzi
* 日  期：2019/11/25
* 版  本：V1.0
************************************************************
*/

#ifndef __QUEUE_LINK_H__
#define __QUEUE_LINK_H__

typedef int             QElemType;/*定义队列的数据类型*/
typedef unsigned char   Status;

#define     OK      1
#define     ERROR   0

/*定义队列的数据结点*/
typedef struct QNode
{
    QElemType data;
	struct QNode *next;
}QNode,*Queue_Ptr;

/*定义队列的链表结构*/
typedef struct 
{
	Queue_Ptr front,rear;/*定义队列的队头和队尾*/
	int count;/*用于记录队列中元素的个数*/
}QueueLink;

Status Queue_Link_Init(QueueLink *Q);
Status Queue_Link_Incert(QueueLink *Q,QElemType value);
Status Queue_Print(QueueLink Q);
Status Queue_Delet(QueueLink *Q,QElemType *value);


#endif