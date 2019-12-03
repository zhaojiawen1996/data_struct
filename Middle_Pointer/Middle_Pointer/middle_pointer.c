#include "middle_pointer.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
//#include "ctype.h"
/*
*****************************************************
* 函数名:Incert_Tail
* 功  能：利用尾插法创建一个长度为n的链表
* 形  参：Linked_List* L：要创建的链表
          int count：要创建的节点个数
* 返回值：OK or ERROR
*****************************************************
*/
Status Incert_Tail(Linked_List* L,int count)
{
	Linked_List P,Q;
	int i;
	srand(time(0));
	(*L) = (Linked_List)malloc(sizeof(Node));/*为头结点分配内存空间*/
	Q = (Linked_List)malloc(sizeof(Node));
	Q = (*L);
	for(i = 0;i < count;i++)
	{
	    P = (Linked_List)malloc(sizeof(Node));
		P->data = rand()%100 + 1;/*随记生成100以内的数*/
		P->next = NULL;
	    Q->next = P; 
		Q = P;
	}
	return OK;
}


/*
**************************************************
* 函数名：Print_List
* 功  能：将链表中的元素输出
* 形  参：Linked_List L:要输出的链表
* 返回值：空
**************************************************
*/
void Print_List(Linked_List L)
{
	Linked_List P;
	P = L;
	printf("The Element of Linked List is:\n");
	while(P->next != NULL)
	{
		P = P->next;
		printf("%d ",P->data);
	}
	printf("\n");
}


/*
*****************************************************
* 函数名：Middle_Pointer
* 功  能：将链表中中间节点的元素输出
* 形  参: Linked_List L：要进行操作的链表
          int *value：用于存储于输出的数据
* 返回值：OK or ERROR
*****************************************************
*/
Status Middle_Pointer(Linked_List L,int *value)
{
    Linked_List search,mid;
	search = L;
	mid = L;
	while(search->next != NULL)
	{
		if(search->next->next != NULL)
		{
		    search = search->next->next;
			mid = mid->next;
		}
		else
		{
			search = search->next;
		}
	}
	*value = mid->data;
	return OK;
}