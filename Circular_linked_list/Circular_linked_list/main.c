#include "stdio.h"
#include "circular_linked_list.h"

LinkedList L;

int main(void)
{
    Creat_Circular_list_head(&L,5);
	printf("The List data is:\n");
	Show_List(L);
	Creat_Circular_list_Tail(&L,5);
	printf("The List data is:\n");
	Show_List(L);
}
