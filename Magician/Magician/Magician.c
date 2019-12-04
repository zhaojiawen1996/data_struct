/*
************************************************
* 文件名：Magician.c
* 作  者：wenzi
* 日  期：2019/12/4
* 版  本：V1.0
***********************************************
*/
#include "Magician.h"
#include "stdio.h"
#include "stdlib.h"


#if 0
Status Creat_List(Linked_List *L)
{
    //Linked_List head;
	Linked_List R,P;
	int count,i;
	printf("Please Input the number of the cards:\ns");
	scanf("%d",&count);
	*L = (Linked_List)malloc(sizeof(sqlist));
	R = (Linked_List)malloc(sizeof(sqlist));
	(*L)->next = NULL;
	R = (*L);
	for(i = 0;i < count;i++)
	{
		P = (Linked_List)malloc(sizeof(sqlist));
		P->data = 0;
		R->next = P;
		R = P;
	}
	R->next = (*L);
	return OK;
}
#else 
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
    printf("Please Input the number of the cards:\n");
	scanf("%d",&(L->count));
	L->head->next = (Linked_List)malloc(sizeof(sqlist));
	L->head->next->data = L->count;/*将结点的个数单独作为一个结点，作为头结点放在链表的第一个结点*/ 
	Q = L->head->next;
	for(i = 0;i < L->count;i++)
	{
	    P = (Linked_List)malloc(sizeof(sqlist));
		P->data = 0;
		Q->next = P;
		Q = P;
	}
	Q->next = L->head->next->next;/*尾部指向头结点的下一个结点*/
	return OK; 
}
#endif


Status Print_List(LinkedList L)
{
	int i;
    Linked_List P;
	P = (Linked_List)malloc(sizeof(sqlist));
	P = L.head->next->next;
	printf("The Element of the List is:\n");
	for(i = 0;i < L.count;i++)
	{
		printf("%d ",P->data);
		P = P->next;
	}
	printf("\n");
	return OK;
}


/*
*****************************************************
* 函数名：Creat_Cards_Order
* 功  能：创建牌的顺序
* 形  参：LinkedList *L：要创建的链表
* 返回值：OK or ERROR
*****************************************************
*/
Status Creat_Cards_Order(LinkedList *L)
{
    int countnum,i;
	Linked_List P;
	P = (Linked_List)malloc(sizeof(sqlist));
	countnum = 2;
	P = L->head->next->next;
	P->data = 1;/*第一张牌为1*/
	while(countnum != 14)
	{
        for(i = 1;i <= countnum;i++)
		{
			P = P->next;
			if(P->data != 0)
			{
				i--;
			}
	    }
		if(P->data == 0)
		{
			P->data = countnum;
			countnum ++;
		}
	}
    return OK;
}