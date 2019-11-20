#include "SqQueue.h"
#include "stdio.h"

SqQueue_st Queue;


int main(void)
{
	int value;
    Queue_Init(&Queue);
	Queue_Incert(&Queue,1);
	Queue_Incert(&Queue,2);
	Queue_Incert(&Queue,3);
	Queue_Incert(&Queue,4);
#if UnDebug
	Queue_Incert(&Queue,5);/*最大只允许插入 MAXSIZE-1 个元素*/
#endif
	//printf("%d\n",Queue.rear);
	Queue_Out(&Queue,&value);
	Queue_Out(&Queue,&value);
	//printf("%d\n",Queue.front);
	Queue_Incert(&Queue,6);
	Queue_Incert(&Queue,7);
	//printf("%d\n",Queue.rear);
	Queue_Print(Queue);
}