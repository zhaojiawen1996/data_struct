#include "BiTreeLink.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
**************************************************
* 函数名：InitBiTree
* 功  能：初始化树结点
* 形  参：BiTree *T：要构建的树
* 返回值：OK or ERROR
**************************************************
*/
Status InitBiTree(BiTree *T)
{
	(*T) = NULL;
	return OK;
}

/*
**************************************************
* 函数名：DestroyBiTree
* 功  能：销毁树结点
* 形  参：BiTree *T：要销毁的树
* 返回值：OK or ERROR
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
		free(*T);/*释放结点*/
		(*T) = 0;/*空结点赋值为0*/
	}
	return OK;
}

/*
**************************************************
* 函数名：CreatBiTreePre
* 功  能：运用前序序列的方法创建二叉树
* 形  参：BiTree *T：要创建的树
* 返回值：OK or ERROR
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
* 函数名：PreOrderTraverse
* 功  能：运用前序遍历的方法遍历整棵二叉树
* 形  参：BiTree *T：目标树
* 返回值：void
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
* 函数名：InOrderTraverse
* 功  能：中序遍历整个二叉树
* 形  参：BiTree *T：要遍历的目标树
* 返回值：void空
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
* 函数名：PostOrderTraverse
* 功  能：后序遍历整个二叉树
* 形  参：BiTree *T：要遍历的目标树
* 返回值：void空
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
* 函数名：BiTreeDepth
* 功  能：求二叉树的深度
* 形  参：BiTree T:要求的目标
* 返回值：树的深度
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
* 函数名：BiTreeEmpty
* 功  能：判断二叉树是否为空
* 形  参：BiTree T:要判断的目标
* 返回值：TRUE or FALSE
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
* 函数名：Root
* 功  能：返回树的根结点
* 形  参：BiTree T:要判断的目标
* 返回值：根结点的值
****************************************************
*/
TElemType Root(BiTree T)
{
    if(T)
		return T->data;
	else
		return 0;
}