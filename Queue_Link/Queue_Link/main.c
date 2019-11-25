#include "stdio.h"
#include "stdlib.h"
#include "Queue_Link.h"

QueueLink Q;

int main(void)
{
	QElemType value;
    Queue_Link_Init(&Q);
	Queue_Link_Incert(&Q,1);
	//Queue_Link_Incert(&Q,2);
	//Queue_Link_Incert(&Q,3);
	Queue_Delet(&Q,&value);
	printf("The Delet Value is:%d\n",value);
	Queue_Print(Q);
}