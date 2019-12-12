#include "BiThrTree.h"
#include "stdio.h"
#include "stdlib.h"


/*
*********************************************************
* 函数名：CreatBiTree
* 功  能：创建一棵二叉树
* 形  参：BiThrTree *T：要创建的树
* 返回值：OK or ERROR
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
* 函数名：InThreading
* 功  能：线索化二叉树
* 形  参：未线索化的二叉树：BiThrTree P
* 返回值：空
*****************************************************
*/
BiThrTree Pre;
void InThreading(BiThrTree P)
{
    if(P)
	{
		InThreading(P->lchild);/*递归左子树进行线索化*/
		if(!P->lchild)
		{
			P->lchild = Pre;/*当前结点的左孩子指向前驱*/
			P->LTag = Thread;
		}

		if(!Pre->rchild)
		{
			Pre->RTag = Thread;/*前驱结点的右孩子指向后继*/
			Pre->rchild = P;
		}
		Pre = P;
		InThreading(P->rchild);/*递归右子树进行线索化*/
	}
}

/*
*********************************************************
* 函数名：InOrderThreading
* 功  能：为线索二叉树创建头指针，头指针的左孩子指向根结点
          头指针的右孩子指向中序遍历的最后一个结点，中序遍
		  历的最后一个结点的右孩子指向头指针
* 形  参：BiThrTree *Thr：要创建的头指针
          BiThrTree T：目标树
* 返回值：OK or ERROR
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
		(*Thr)->lchild = (*Thr);/*如果T为空，则指针回指*/
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
* 函数名：InOrderTraverse
* 功  能：中序遍历线索二叉树，并输出二叉树各个结点的值
* 形  参：BiThrTree T：线索二叉树的结点
* 返回值：void
*******************************************************
*/
void InOrderTraverse(BiThrTree T)
{
	BiThrTree P;
	P = T->lchild;/*指向根结点*/
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