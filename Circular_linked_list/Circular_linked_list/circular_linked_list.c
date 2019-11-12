#include "stdio.h"
#include "stdlib.h"
#include "circular_linked_list.h"

/*
*************************************************************
* 函数名：Creat_Circular_list_head
* 功  能：头插法创建循环链表
* 形  参：LinkedList *L：要创建的链表
          int length：   创建的链表的长度
* 返回值：操作是否成功
*************************************************************
*/
Status Creat_Circular_list_head(LinkedList *L,int length)
{
	int i;
	LinkedList P;
	(*L) = (LinkedList)malloc(sizeof(Node));
	(*L)->next = (*L);/*当循环链表为空时，头结点指向他本身*/
	for(i = 0;i < length;i++)
	{
		P = (LinkedList)malloc(sizeof(Node));
		P->data = i;
		P->next = (*L)->next;
		(*L)->next = P;
	}
	return OK;
}

/*
*************************************************************
* 函数名：Creat_Circular_list_Tail
* 功  能：尾插发建立链表
* 形  参：LinkedList *L：要建立的链表
          int length
* 返回值：操作状态
*************************************************************
*/
Status Creat_Circular_list_Tail(LinkedList *L,int length)
{
    int i;
	LinkedList P,R;
	(*L) = (LinkedList)malloc(sizeof(Node));
	R = (*L);
	for(i = 0;i < length;i++)
	{
	    P = (LinkedList)malloc(sizeof(Node));
	  	P->data = i;
	    R->next = P;
		R = P;
	}
	P->next = *L;
	return OK;
}

/*
******************************************************************
* 函数名：Show_List
* 功  能：打印链表中的元素
* 形  参：LinkedList L：要打印的链表
* 返回值：打印的状态
******************************************************************
*/
Status Show_List(LinkedList L)
{
	LinkedList P;
	P = L->next;
	while(P != L)
	{
		printf("%d\n",P->data);
		P = P->next;
	}
	return OK;
}
