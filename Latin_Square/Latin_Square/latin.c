/*
************************************************************************
* 文件名：latin.c
* 作  者：wenzi
* 日  期：2019/12/4
* 版  本：V1.0
*************************************************************************
*/

#include "latin.h"
#include "stdio.h"
#include "stdlib.h"

/*
***********************************************************************
* 函数名：Creat_List
* 功  能：创建一个循环链表，链表分为头指针和头结点，
          头指针用于指向头结点，头结点指向第一个结点，
		  头结点的数据域是用于存储链表的长度
* 形  参:LinkedList *L：要创建的链表
* 返回值：OK or ERROR
***********************************************************************
*/
Status Creat_List(LinkedList *L)
{
	Linked_List P,Q;
	int i;
	L->head = (Linked_List)malloc(sizeof(sqlist));/*定义链表的头指针*/
    Q = (Linked_List)malloc(sizeof(sqlist));
    printf("Please Input the size of the square:\n");
	scanf("%d",&(L->count));
	L->head->next = (Linked_List)malloc(sizeof(sqlist));
	L->head->next->data = L->count;/*将结点的个数单独作为一个结点，作为头结点放在链表的第一个结点*/ 
	Q = L->head->next;
	for(i = 1;i <= L->count;i++)
	{
	    P = (Linked_List)malloc(sizeof(sqlist));
		P->data = i;
		Q->next = P;
		Q = P;
	}
	Q->next = L->head->next->next;/*尾部指向头结点的下一个结点*/
	return OK; 
}

/*
****************************************************
* 函数名：Print_Square
* 功  能：输出拉丁方阵
* 形  参:LinkedList L:存放数据的链表
* 返回值：OK or ERROR
****************************************************
*/
Status Print_Square(LinkedList L)
{
    int i,j;
	Linked_List P,Q;
	P = (Linked_List)malloc(sizeof(sqlist));
	P = L.head->next->next;/*头指针第一次指向头结点，头结点的数据域存放结点的个数*/
	printf("The Latin Square is:\n");
	for(i = 0;i < L.count;i++)
	{
        for(j = 0;j < L.count;j++)
		{
			printf("%d ",P->data);
			P = P->next;
		}
		printf("\n");
		P = P->next;
	}
	return OK;
}
