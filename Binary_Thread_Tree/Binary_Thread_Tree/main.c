#include "BiThrTree.h"
#include "stdio.h"
#include "stdlib.h"

int main(void)
{
    BiThrTree H,T;
	printf("�밴ǰ�����������(�磺'ABDH##I##EJ###CF##G##')\n");
	CreatBiTree(&T);
	InOrderThreading(&H,T);
	printf("��������������������\n");
	InOrderTraverse(H);
	printf("\n");

	return 0;
}