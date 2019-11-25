/*
*************************************************************
* �ļ�����Queue_Link.c
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/25
* ��  ����V1.0
************************************************************
*/

#ifndef __QUEUE_LINK_H__
#define __QUEUE_LINK_H__

typedef int             QElemType;/*������е���������*/
typedef unsigned char   Status;

#define     OK      1
#define     ERROR   0

/*������е����ݽ��*/
typedef struct QNode
{
    QElemType data;
	struct QNode *next;
}QNode,*Queue_Ptr;

/*������е�����ṹ*/
typedef struct 
{
	Queue_Ptr front,rear;/*������еĶ�ͷ�Ͷ�β*/
	int count;/*���ڼ�¼������Ԫ�صĸ���*/
}QueueLink;

Status Queue_Link_Init(QueueLink *Q);
Status Queue_Link_Incert(QueueLink *Q,QElemType value);
Status Queue_Print(QueueLink Q);
Status Queue_Delet(QueueLink *Q,QElemType *value);


#endif