/*
************************************************
* �ļ�����Magician.c
* ��  �ߣ�wenzi
* ��  �ڣ�2019/12/4
* ��  ����V1.0
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
* ��������Creat_List
* ��  �ܣ�����һ��ѭ�����������Ϊͷָ���ͷ��㣬
          ͷָ������ָ��ͷ��㣬ͷ���ָ���һ����㣬
		  ͷ���������������ڴ洢����ĳ���
* ��  ��:LinkedList *L��Ҫ����������
* ����ֵ��OK or ERROR
***********************************************************************
*/
Status Creat_List(LinkedList *L)
{
	Linked_List P,Q;
	int i;
	L->head = (Linked_List)malloc(sizeof(sqlist));/*���������ͷָ��*/
    Q = (Linked_List)malloc(sizeof(sqlist));
    printf("Please Input the number of the cards:\n");
	scanf("%d",&(L->count));
	L->head->next = (Linked_List)malloc(sizeof(sqlist));
	L->head->next->data = L->count;/*�����ĸ���������Ϊһ����㣬��Ϊͷ����������ĵ�һ�����*/ 
	Q = L->head->next;
	for(i = 0;i < L->count;i++)
	{
	    P = (Linked_List)malloc(sizeof(sqlist));
		P->data = 0;
		Q->next = P;
		Q = P;
	}
	Q->next = L->head->next->next;/*β��ָ��ͷ������һ�����*/
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
* ��������Creat_Cards_Order
* ��  �ܣ������Ƶ�˳��
* ��  �Σ�LinkedList *L��Ҫ����������
* ����ֵ��OK or ERROR
*****************************************************
*/
Status Creat_Cards_Order(LinkedList *L)
{
    int countnum,i;
	Linked_List P;
	P = (Linked_List)malloc(sizeof(sqlist));
	countnum = 2;
	P = L->head->next->next;
	P->data = 1;/*��һ����Ϊ1*/
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