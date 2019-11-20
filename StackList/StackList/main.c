#include "stdio.h"
#include "StackList.h"


StackLink S;


int main(void)
{
	char i;
	SElemType value;
    Stack_Link_Init(&S);
	for(i = 0;i < 5;i ++)
	{
	    Stack_Link_Push(&S,i);    
	}
	Show_Stack_List(S);
	Stack_Link_Pop(&S,&value);
	printf("The Pop value is :%d\n",value);
	Show_Stack_List(S);
}

