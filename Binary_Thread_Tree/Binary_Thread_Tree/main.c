#include "BiThrTree.h"
#include "stdio.h"
#include "stdlib.h"

int main(void)
{
    BiThrTree H,T;
	printf("请按前序输入二叉树(如：'ABDH##I##EJ###CF##G##')\n");
	CreatBiTree(&T);
	InOrderThreading(&H,T);
	printf("中序遍历输出二叉线索树\n");
	InOrderTraverse(H);
	printf("\n");

	return 0;
}