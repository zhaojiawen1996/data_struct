#include "middle_pointer.h"
#include "stdio.h"
#include "stdlib.h"

Linked_List L;

int main(void)
{
	int value;
    Incert_Tail(&L,20);
	Print_List(L);
	Middle_Pointer(L,&value);
	printf("%d\n",value);
}