#include "stacklist.h"
#include "stdio.h"
#include "stdlib.h"


SqStack S;
ShStack S_Stack;

int main(void)
{
	SElemType value;
	int i;
	value = 5;
	SqStack_Init(&S);
	SqStack_Push(&S,value);
	Show_List(S);
	SqStack_Pop(&S,&value);
	Share_Stack_Init(&S_Stack);
	for(i = 0;i < 5;i++)
	{
	    Share_Stack_Push(&S_Stack,i,1);    
	}
    for(i = 0;i < 5;i++)
	{
	    Share_Stack_Push(&S_Stack,i,2);    
	}
	Show_ShList(S_Stack);
}