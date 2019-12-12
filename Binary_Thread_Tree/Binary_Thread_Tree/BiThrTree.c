#include "BiThrTree.h"
#include "stdio.h"
#include "stdlib.h"


/*
*********************************************************
* ��������CreatBiTree
* ��  �ܣ�����һ�ö�����
* ��  �Σ�BiThrTree *T��Ҫ��������
* ����ֵ��OK or ERROR
**********************************************************
*/
Status CreatBiTree(BiThrTree *T)
{
    char ch;
	scanf("%c",&ch);
	if(ch == Nil)
		(*T) = NULL;
	else
	{
		(*T) = (BiThrTree)malloc(sizeof(BiThrNode));
		if(!(*T))
			return ERROR;
	    (*T)->data =  ch;
	    CreatBiTree(&(*T)->lchild);
	    if((*T)->lchild)
		    (*T)->LTag = link;
	    CreatBiTree(&(*T)->rchild);
	    if((*T)->rchild)
		    (*T)->RTag = link;
	}
	return OK;
}

/*
******************************************************
* ��������InThreading
* ��  �ܣ�������������
* ��  �Σ�δ�������Ķ�������BiThrTree P
* ����ֵ����
*****************************************************
*/
BiThrTree Pre;
void InThreading(BiThrTree P)
{
    if(P)
	{
		InThreading(P->lchild);/*�ݹ�����������������*/
		if(!P->lchild)
		{
			P->lchild = Pre;/*��ǰ��������ָ��ǰ��*/
			P->LTag = Thread;
		}

		if(!Pre->rchild)
		{
			Pre->RTag = Thread;/*ǰ�������Һ���ָ����*/
			Pre->rchild = P;
		}
		Pre = P;
		InThreading(P->rchild);/*�ݹ�����������������*/
	}
}

/*
*********************************************************
* ��������InOrderThreading
* ��  �ܣ�Ϊ��������������ͷָ�룬ͷָ�������ָ������
          ͷָ����Һ���ָ��������������һ����㣬�����
		  �������һ�������Һ���ָ��ͷָ��
* ��  �Σ�BiThrTree *Thr��Ҫ������ͷָ��
          BiThrTree T��Ŀ����
* ����ֵ��OK or ERROR
**********************************************************
*/
Status InOrderThreading(BiThrTree *Thr,BiThrTree T)
{
    (*Thr) = (BiThrTree)malloc(sizeof(BiThrNode));
	if(!(*Thr))
		return ERROR;
	(*Thr)->LTag = link;
	(*Thr)->RTag = Thread;
	(*Thr)->lchild = T;
	if(!T)
		(*Thr)->lchild = (*Thr);/*���TΪ�գ���ָ���ָ*/
	else
	{
		(*Thr)->RTag = Thread;
	    Pre = (*Thr);
		InThreading(T);
		Pre->RTag = Thread;
		Pre->rchild = (*Thr);
		(*Thr)->rchild = Pre;
	}
	return OK;
}


/*
******************************************************
* ��������InOrderTraverse
* ��  �ܣ���������������������������������������ֵ
* ��  �Σ�BiThrTree T�������������Ľ��
* ����ֵ��void
*******************************************************
*/
void InOrderTraverse(BiThrTree T)
{
	BiThrTree P;
	P = T->lchild;/*ָ������*/
	while(P != T)
	{
		while(P->LTag == link)
		    P = P->lchild;
	    printf("%c",P->data);
	    while(P->RTag == Thread && P->rchild != T)
	    {
		   P = P->rchild;
		   printf("%c",P->data);
	    }
		P = P->rchild;
	}
	return ; 
}