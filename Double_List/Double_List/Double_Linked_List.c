/*
**************************************************************
* 文件名：Double_Linked_List.c
* 作  者：wenzi
* 日  期：2019/11/12
* 版  本：v1.0
*************************************************************
*/

#include "Double_Linked_List.h"
#include "stdio.h"
#include "stdlib.h"

/*
****************************************************************
* 函数名：Init_List
* 功  能：初始化双向循环链表
* 形  参：DuLinked_List *L：要初始化的链表
* 返回值：操作的状态
****************************************************************
*/
Status Init_List(DuLinked_List *L)
{

	*L = (DuLinked_List)malloc(sizeof(Node));
	(*L)->next = (*L);
	(*L)->prior = (*L);
	return OK;
}

/*
****************************************************************
* 函数名：Creat_List_Tail
* 功  能：尾插法建立链表
* 形  参：DuLinked_List *L：要建立的链表
          int length：建立的链表长度
		  int value：链表存储的值 
* 返回值：操作的状态
****************************************************************
*/
Status Creat_List_Tail(DuLinked_List *L,int length,int value)
{
	int i;
	DuLinked_List P,R;
	R = (DuLinked_List)malloc(sizeof(Node));
	R = (*L);
	for(i = 0;i < length;i++)
	{
	    P = (DuLinked_List)malloc(sizeof(Node));
		P->data = value + i;

		P->prior = R;
		P->next = R->next;
		R->next->prior = P;
		R->next = P;

		R = P;
	}
	return OK;
}

/*
**********************************************************************
* 函数名：Creat_List_Head
* 功  能：运用头插法创建链表
* 形  参：DuLinked_List *L：创建的链表
          int length：      链表的长度
		  int value ：      存储到链表的值
* 返回值：链表操作的状态
**********************************************************************
*/
Status Creat_List_Head(DuLinked_List *L,int length,int value)
{
    int i;
	DuLinked_List P;
	for(i = 0;i < length;i ++)
	{
	    P = (DuLinked_List)malloc(sizeof(Node));
		P->data = value + i;
		P->prior = (*L);
		P->next = (*L)->next;
		(*L)->next->prior = P;
		(*L)->next = P;
	}
	return OK;
}


/*
*****************************************************************
* 函数名：Incert_List
* 功  能：在链表中插入一个元素
* 形  参：DuLinked_List *L：已有的链表
          int position    ：插入的位置
		  int value       ：插入的数值
* 返回值：操作状态
*****************************************************************
*/
Status Incert_List(DuLinked_List *L,int position,int value)
{
    int i;
	DuLinked_List P,R;
	R = (DuLinked_List)malloc(sizeof(Node));
	P = (DuLinked_List)malloc(sizeof(Node));
	P = (*L);
	for(i = 1;i < position;i++)
	{
		P = P->next;
	}
	R->data = value;
	R->prior = P;
	R->next  = P->next;
	P->next->prior = R;
	P->next = R;
	return OK;
}



/*
******************************************************************
* 函数名：Delet_List
* 功  能：在已有链表中删除一个元素
* 形  参：DuLinked_List *L：已有的链表
          int position    ：删除的位置
		  int *value      ：存储删除结点的数值
* 返回值：操作的状态
*****************************************************************
*/
Status Delet_List(DuLinked_List *L,int position,int *value)
{
     int i;
	 DuLinked_List P,R;
	 R = (DuLinked_List)malloc(sizeof(Node));
	 P = (DuLinked_List)malloc(sizeof(Node));
	 P = (*L);
	 for(i = 1;i < position;i++)
	 {
		 P = P->next;
	 }
	 R = P->next;
	 *value = R->data;
	 P->next = R->next;
	 R->next->prior = P;
	 printf("The Delet value is:\n");
	 printf("%d\n",*value);
	 free(R);
	 return OK;
}

/*
************************************************************
* 函数名：Length_List
* 功  能：求出已知链表的长度
* 形  参：DuLinked_List L：已有的链表
* 返回值：length：链表的长度
************************************************************
*/
int Length_List(DuLinked_List L)
{
	int length;
    DuLinked_List P;
	P = L->next;
	length = 0;
	while(P != L)
	{
	    length ++;
		P = P->next;
	}
	return length;
}

/*
*******************************************************
* 函数名：Show_List
* 功  能：输出链表中的元素
* 形  参：要输出的链表
* 返回值：操作的状态
*******************************************************
*/
Status Show_List(DuLinked_List L)
{
    int i;
	DuLinked_List P;
	P = L->next;
	printf("The List data is:\n");
	while(P != L)
	{
		printf("%d\n",P->data);
		P = P->next;
	}
}
