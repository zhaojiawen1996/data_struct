#include "BiTreeLink.h"
#include "stdio.h"
#include "stdlib.h"


int main(void)
{
	BiTree T;
	TElemType e;
	InitBiTree(&T);
	printf("�������������Ԫ��:\n");
	CreatBiTreePre(&T);
	printf("��������������շ�%d(1�ǿ� 0�Ƿǿ�)���������Ϊ%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e = Root(T);
	printf("�������ĸ�Ϊ��%c\n",e);
	printf("ǰ�������������ֵ��\n");
	PreTraverse(T);
	printf("���������������ֵ��\n");
	InTraverse(&T);
	printf("���������������ֵ��\n");
	PostOrder(&T);
	DestroyBiTree(&T);
	printf("��������������շ�%d(1�ǿ� 0�Ƿǿ�)���������Ϊ%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e = Root(T);
	if(!e)
		printf("���գ��޸�\n");
}