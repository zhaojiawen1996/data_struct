/*
**************************************************************
* �ļ�����Double_Linked_List.c
* ��  �ߣ�wenzi
* ��  �ڣ�2019/11/12
* ��  ����v1.0
*************************************************************
*/

#include "Double_Linked_List.h"
#include "stdio.h"
#include "stdlib.h"

/*
****************************************************************
* ��������Init_List
* ��  �ܣ���ʼ��˫��ѭ������
* ��  �Σ�DuLinked_List *L��Ҫ��ʼ��������
* ����ֵ��������״̬
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
* ��������Creat_List_Tail
* ��  �ܣ�β�巨��������
* ��  �Σ�DuLinked_List *L��Ҫ����������
          int length��������������
		  int value������洢��ֵ 
* ����ֵ��������״̬
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
* ��������Creat_List_Head
* ��  �ܣ�����ͷ�巨��������
* ��  �Σ�DuLinked_List *L������������
          int length��      ����ĳ���
		  int value ��      �洢�������ֵ
* ����ֵ�����������״̬
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
* ��������Incert_List
* ��  �ܣ��������в���һ��Ԫ��
* ��  �Σ�DuLinked_List *L�����е�����
          int position    �������λ��
		  int value       ���������ֵ
* ����ֵ������״̬
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
* ��������Delet_List
* ��  �ܣ�������������ɾ��һ��Ԫ��
* ��  �Σ�DuLinked_List *L�����е�����
          int position    ��ɾ����λ��
		  int *value      ���洢ɾ��������ֵ
* ����ֵ��������״̬
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
* ��������Length_List
* ��  �ܣ������֪����ĳ���
* ��  �Σ�DuLinked_List L�����е�����
* ����ֵ��length������ĳ���
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
* ��������Show_List
* ��  �ܣ���������е�Ԫ��
* ��  �Σ�Ҫ���������
* ����ֵ��������״̬
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
