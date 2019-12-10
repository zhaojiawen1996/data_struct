#include "BiTreeLink.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
**************************************************
* ��������InitBiTree
* ��  �ܣ���ʼ�������
* ��  �Σ�BiTree *T��Ҫ��������
* ����ֵ��OK or ERROR
**************************************************
*/
Status InitBiTree(BiTree *T)
{
	(*T) = NULL;
	return OK;
}

/*
**************************************************
* ��������DestroyBiTree
* ��  �ܣ����������
* ��  �Σ�BiTree *T��Ҫ���ٵ���
* ����ֵ��OK or ERROR
**************************************************
*/
Status DestroyBiTree(BiTree *T)
{
    if(*T)
	{
		if((*T)->lchild)
		    DestroyBiTree(&((*T)->lchild));    
		if((*T)->rchild)
			DestroyBiTree(&((*T)->rchild));
		free(*T);/*�ͷŽ��*/
		(*T) = 0;/*�ս�㸳ֵΪ0*/
	}
	return OK;
}

/*
**************************************************
* ��������CreatBiTreePre
* ��  �ܣ�����ǰ�����еķ�������������
* ��  �Σ�BiTree *T��Ҫ��������
* ����ֵ��OK or ERROR
**************************************************
*/
Status CreatBiTreePre(BiTree *T)
{
    TElemType  ch;
	scanf("%c",&ch);
	if(ch == '#')
		(*T) = NULL;
	else
	{
		(*T) = (BiTree)malloc(sizeof(BiTNode));
	    if(!(*T))
		    return;
		(*T)->data = ch;
		CreatBiTreePre(&((*T)->lchild));
		CreatBiTreePre(&((*T)->rchild));
	}
	return OK;
}


/* 
*************************************************
* ��������PreOrderTraverse
* ��  �ܣ�����ǰ������ķ����������ö�����
* ��  �Σ�BiTree *T��Ŀ����
* ����ֵ��void
*************************************************
*/
void PreOrderTraverse(BiTree T)
{
    if(T == NULL)
	    return;
	printf("%c",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->rchild);
}

void PreTraverse(BiTree T)
{
    printf("This BiTree Element is:\n");
	PreOrderTraverse(T);
	printf("\n");
}


/*
**************************************************
* ��������InOrderTraverse
* ��  �ܣ������������������
* ��  �Σ�BiTree *T��Ҫ������Ŀ����
* ����ֵ��void��
**************************************************
*/
void InOrderTraverse(BiTree *T)
{
    if(*T == NULL)
		return;
	InOrderTraverse(&(*T)->lchild);
	printf("%c",(*T)->data);
	InOrderTraverse(&(*T)->rchild);
}

void InTraverse(BiTree *T)
{
    printf("This BiTree Element is :\n");
	InOrderTraverse(T);
	printf("\n");
}

/*
**************************************************
* ��������PostOrderTraverse
* ��  �ܣ������������������
* ��  �Σ�BiTree *T��Ҫ������Ŀ����
* ����ֵ��void��
**************************************************
*/
void PostOrderTraverse(BiTree *T)
{
    if((*T) == NULL)
		return;
	PostOrderTraverse(&(*T)->lchild);
	PostOrderTraverse(&(*T)->rchild);
	printf("%c",(*T)->data);
}

void PostOrder(BiTree *T)
{
    printf("The BiTree Element is:\n");
	PostOrderTraverse(T);
	printf("\n");
}

/*
****************************************************
* ��������BiTreeDepth
* ��  �ܣ�������������
* ��  �Σ�BiTree T:Ҫ���Ŀ��
* ����ֵ���������
****************************************************
*/
int BiTreeDepth(BiTree T)
{
    int i,j;
	if(T == NULL)
		return 0;
	if(T->lchild)
		i = BiTreeDepth(T->lchild);
	else
		i = 0;
	if(T->rchild)
		j = BiTreeDepth(T->rchild);
	else
		j = 0;
	return i>j?i+1:j+1;
}

/*
****************************************************
* ��������BiTreeEmpty
* ��  �ܣ��ж϶������Ƿ�Ϊ��
* ��  �Σ�BiTree T:Ҫ�жϵ�Ŀ��
* ����ֵ��TRUE or FALSE
****************************************************
*/
Status BiTreeEmpty(BiTree T)
{
    if(T)
		return FALSE;
	else
		return TRUE;
}

/*
****************************************************
* ��������Root
* ��  �ܣ��������ĸ����
* ��  �Σ�BiTree T:Ҫ�жϵ�Ŀ��
* ����ֵ��������ֵ
****************************************************
*/
TElemType Root(BiTree T)
{
    if(T)
		return T->data;
	else
		return 0;
}