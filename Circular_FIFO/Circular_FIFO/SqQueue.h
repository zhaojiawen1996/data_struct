#ifndef __SQQUEUE_H__
#define __SQQUEUE_H__


typedef int            SqElemType;
typedef unsigned char  Status;



#define    ERROR   0
#define    OK      1

#define MAXSIZE  5

typedef struct
{
	SqElemType data[MAXSIZE]; /*数据域*/
	int front;                /*头指针*/
	int rear;                 /*尾指针*/
}SqQueue_st;


int Queue_Length(SqQueue_st Queue);
Status Queue_Out(SqQueue_st *Queue,SqElemType *value);
Status Queue_Incert(SqQueue_st *Queue,SqElemType value);
Status Queue_Init(SqQueue_st *Queue);
Status Queue_Print(SqQueue_st Queue);


#endif