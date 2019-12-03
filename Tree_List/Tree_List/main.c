#include "PTree.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int main(void)
{
	PTree T;
	InitTree(&T);
    CreateTree(&T);
	while(1)
	{
	    Find_Tree(&T);
	}
}