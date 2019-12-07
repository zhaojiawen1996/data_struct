#include "BiTreeArry.h"
#include "stdio.h"
#include "string.h"

BiTree T;

int main(void)
{
	int depth,i,j;
	TElemType e;
	position pos;
    BiTree_Init(T);
	Creat_BiTree(T);
	printf("�����������շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	if(root(T,&e))
	{
	    printf("�������ĸ�Ϊ��%c\n",e);
	}
	else
	{
	    printf("���գ��޸�\n");
	}
	printf("�������������:\n");
	LevelOrderTraverse(T);
	printf("ǰ�����������:\n");
	PreOrderTraverse(T);
	printf("�������������:\n");
	InTraverse(T,0);
	printf("�������������:\n");
	PostTraverse(T,0);
	printf("������Ҫ���ĵ����Ĳ�ź����:\n");
	scanf("%d %d",&i,&j);
	pos.level = i;
	pos.order = j;
	e = value(T,pos);
	printf("���޸ĵ�ԭֵΪ%c,��������ֵ��",e);
	fflush(stdin);
	scanf("%c",&e);
	Assign(T,pos,e);
	printf("�ٴ�ǰ������������е�Ԫ��:\n");
	PreOrderTraverse(T);
	printf("���Ϊ%c��˫��Ϊ%c,���Һ��ӷֱ�Ϊ��%c,%c",e,parent(T,e),Leftchild(T,e),Rightchild(T,e));
	printf("�����ֵ�Ϊ��%c,%c",LeftSlibing(T,e),RightSlibing(T,e));
	ClearTree(T);
	printf("��������������շ�%d(1:�� 0:��) �������=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    if(root(T,&e))
	{
	    printf("�������ĸ�Ϊ��%c\n",e);
	}
	else
	{
	    printf("���գ��޸�\n");
	}
}