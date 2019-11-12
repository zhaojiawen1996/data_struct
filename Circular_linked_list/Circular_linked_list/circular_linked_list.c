#include "stdio.h"
#include "stdlib.h"
#include "circular_linked_list.h"

/*
*************************************************************
* ��������Creat_Circular_list_head
* ��  �ܣ�ͷ�巨����ѭ������
* ��  �Σ�LinkedList *L��Ҫ����������
          int length��   ����������ĳ���
* ����ֵ�������Ƿ�ɹ�
*************************************************************
*/
Status Creat_Circular_list_head(LinkedList *L,int length)
{
	int i;
	LinkedList P;
	(*L) = (LinkedList)malloc(sizeof(Node));
	(*L)->next = (*L);/*��ѭ������Ϊ��ʱ��ͷ���ָ��������*/
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
* ��������Creat_Circular_list_Tail
* ��  �ܣ�β�巢��������
* ��  �Σ�LinkedList *L��Ҫ����������
          int length
* ����ֵ������״̬
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
* ��������Show_List
* ��  �ܣ���ӡ�����е�Ԫ��
* ��  �Σ�LinkedList L��Ҫ��ӡ������
* ����ֵ����ӡ��״̬
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
