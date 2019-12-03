#include "PTree.h"
#include "string.h"
#include "stdio.h"

/*
*******************************************
* ��������InitTree
* ��  �ܣ�����һ������
* ��  �Σ�PTree *T:Ҫ��������
* ����ֵ��OK or ERROR
*******************************************
*/
Status InitTree(PTree *T)
{
	T->r = 0;/*���Ľ�㴦���������λ��*/
	T->n = 1;/*ֻ�и����һ�����*/
	T->nodes[T->r].data = '0';
	T->nodes[T->r].parents = -1;
	return OK;
}


Status CreateTree(PTree *T)
{
	int i;
	printf("Please Input the number of Nodes\n");
	scanf("%d",&(T->n));
	printf("Please Input the Tree's value and parents value\n");
	for(i = 0;i < T->n;i++)
	{
		fflush(stdin);
		scanf("%c,%d",&T->nodes[i].data,&(T->nodes[i].parents));
	}
	return OK;
}

Status Find_Tree(PTree *T)
{
    int i;
	printf("Please Input the number that we want to find:\n");
	scanf("%d",&i);
	printf("The Parents of the %c is %d\n",T->nodes[i].data,T->nodes[i].parents);
}