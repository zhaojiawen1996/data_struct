/*
*******************************************************************
* 文件名：link_list.c
* 作  者：wenzi
* 邮  箱：1164481458@qq.com
* 日  期：2019/11/3
*******************************************************************
*/

#include "link_list.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/*
**************************************************************
* 函数名：GetElem
* 形  参：Linklist p :    进行操作的链表
          int position：  查找的位置
		  ElemType *value：存储查找到的元素
* 功  能：在指定位置查找链表中的数据
* 返回值：
*************************************************************
*/
Status GetElem(Linklist L,int position,ElemType *value)
{
    int j;
	Linklist P;
	P = L->next;
	for(j = 1;j < position;j++)
	{
		P = P->next;
		if(NULL == P->next)
		{
			printf("Don't found the same value");
		    return ERROR;
		}
	}
	*value = P->data;
	printf("The value is:%d\n",*value);
	return OK;
}

/*
*****************************************************************
* 函数名：Creat_List_Head
* 功  能：头插法创建固定长度的链表
* 形  参：
* 返回值：
*****************************************************************
*/
#if 1
Status Creat_List_Head(Linklist *L,int n)
{
	Linklist P;
	int i;
	//srand(time(0));
	*L = (Linklist)malloc(sizeof(Node));/*为头结点分配存储空间*/
	(*L)->next = NULL;
	for(i = 0;i < n;i++)
	{
	    P = (Linklist)malloc(sizeof(Node));
		P->data = i;/*The value of 0-100*/
		P->next = (*L)->next;
		(*L)->next = P;
	}
	return OK;
}

#else
Status Creat_List_Head(Node *L,int n)
{
	Node *P;
	int i;
	//srand(time(0));
	L = (Node *)malloc(sizeof(Node));/*为头结点分配存储空间*/
	L->next = NULL;
	for(i = 0;i < n;i++)
	{
	    P = (Linklist)malloc(sizeof(Node));
		P->data = i;/*The value of 0-100*/
		P->next = L->next;
		L->next = P;
	}
	return OK;
}
#endif

/*
***********************************************************
* 函数名：Creat_List_Tail
* 功  能：尾插法建立固定长度的链表
* 形  参：Linklist *L：要建立的链表
          int n：      要建立的链表长度
* 返回值：
***********************************************************
*/
Status Creat_List_Tail(Linklist *L, int n)
{
	Linklist r, p;
	int i;
	(*L) = (Linklist)malloc(sizeof(Node));/*创建头结点，使得第一个元素的插入和其他位置元素的插入方法一致*/
	r = (*L);
	for (i = 0;i < n;i++)
	{
		p = (Linklist)malloc(sizeof(Node));
		p->data = i;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return OK;
}

/*
***************************************************************
* 函数名：ListIncert
* 功  能: 在已有链表中插入一个新的结点
* 形  参：Linklist *L：   已有的链表
          int position：  结点位置
		  ElemType value：插入的数值
* 返回值：
***************************************************************
*/
Status ListIncert(Linklist *L, int position,ElemType value)
{
	Linklist P,S;
	P = *L;
	int i;
	for (i = 1;i < position;i++)
	{
		P = P->next;
		if (P == NULL)
		{
			return ERROR;
		}
	}
	S = (Linklist)malloc(sizeof(Node));
	S->data = value;
	S->next = P->next;
	P->next = S;
	return OK;
}


/*
***************************************************************
* 函数名：ListDelet
* 功  能：删除链表中指定位置的元素
* 形  参：Linklist *L:     已有的链表
          int position：   删除的结点的位置
		  ElemType *value：存储删除的结点的数据
* 返回值：
***************************************************************
*/
Status ListDelet(Linklist *L, int position, ElemType *value)
{
	Linklist P,Q;
	int i;
	P = (*L);
	for (i = 1;i < position;i++)
	{
		P = P->next;
		if (NULL == P)
		{
			return ERROR;
		}
	}
	Q = P->next;
	*value = Q->data;
	P->next = Q->next;
	printf("The delet value is :%d\n", *value);
	free(Q);
	return OK;
}

/*
*************************************************************
* 函数名：ClearList
* 功  能：删除整个链表（一个结点一个结点的删除）
* 形  参：Linklist *L：进行操作的链表
* 返回值：
*************************************************************
*/
Status ClearList(Linklist *L)
{
	Linklist P, Q;
	P = (*L)->next;
	while (P)
	{
		Q = P->next;
		free(P);
		P = Q;
	}
	(*L)->next = NULL;/*将头结点的指针域变为0*/
	return OK;
}

/*
*****************************************************************
* 函数名：Show_List
* 功  能：输出链表中的元素
* 形  参：Linklist *L：进行操作的链表
* 返回值：空
*****************************************************************
*/
#if 1
void Show_List(Linklist *L)
{
	Linklist P;
	P = (Linklist)malloc(sizeof(Node));
	P = (*L)->next;
	printf("The List data is :\n");
	while(NULL != P)
	{
		printf("%d\n",P->data);
		P = P->next;
	}
}

#else 
void Show_List(Node *L)
{
	Node *P;
	P = (Linklist)malloc(sizeof(Node));
	P = L->next;
	printf("The List data is :\n");
	while(NULL != P)
	{
		printf("%d\n",P->data);
		P = P->next;
	}
}
#endif


