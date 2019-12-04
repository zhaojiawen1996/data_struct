#include "Magician.h"
#include "stdio.h"
#include "stdlib.h"


LinkedList L;

int main(void)
{
    Creat_List(&L);
	Print_List(L);
	Creat_Cards_Order(&L);
	Print_List(L);
}