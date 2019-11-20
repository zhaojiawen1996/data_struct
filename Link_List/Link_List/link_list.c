/*
*******************************************************************
* �ļ�����link_list.c
* ��  �ߣ�wenzi
* ��  �䣺1164481458@qq.com
* ��  �ڣ�2019/11/3
*******************************************************************
*/

#include "link_list.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/*
**************************************************************
* ��������GetElem
* ��  �Σ�Linklist p :    ���в���������
          int position��  ���ҵ�λ��
		  ElemType *value���洢���ҵ���Ԫ��
* ��  �ܣ���ָ��λ�ò��������е�����
* ����ֵ��
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
* ��������Creat_List_Head
* ��  �ܣ�ͷ�巨�����̶����ȵ�����
* ��  �Σ�
* ����ֵ��
*****************************************************************
*/
#if 1
Status Creat_List_Head(Linklist *L,int n)
{
	Linklist P;
	int i;
	//srand(time(0));
	*L = (Linklist)malloc(sizeof(Node));/*Ϊͷ������洢�ռ�*/
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
	L = (Node *)malloc(sizeof(Node));/*Ϊͷ������洢�ռ�*/
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
* ��������Creat_List_Tail
* ��  �ܣ�β�巨�����̶����ȵ�����
* ��  �Σ�Linklist *L��Ҫ����������
          int n��      Ҫ������������
* ����ֵ��
***********************************************************
*/
Status Creat_List_Tail(Linklist *L, int n)
{
	Linklist r, p;
	int i;
	(*L) = (Linklist)malloc(sizeof(Node));/*����ͷ��㣬ʹ�õ�һ��Ԫ�صĲ��������λ��Ԫ�صĲ��뷽��һ��*/
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
* ��������ListIncert
* ��  ��: �����������в���һ���µĽ��
* ��  �Σ�Linklist *L��   ���е�����
          int position��  ���λ��
		  ElemType value���������ֵ
* ����ֵ��
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
* ��������ListDelet
* ��  �ܣ�ɾ��������ָ��λ�õ�Ԫ��
* ��  �Σ�Linklist *L:     ���е�����
          int position��   ɾ���Ľ���λ��
		  ElemType *value���洢ɾ���Ľ�������
* ����ֵ��
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
* ��������ClearList
* ��  �ܣ�ɾ����������һ�����һ������ɾ����
* ��  �Σ�Linklist *L�����в���������
* ����ֵ��
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
	(*L)->next = NULL;/*��ͷ����ָ�����Ϊ0*/
	return OK;
}

/*
*****************************************************************
* ��������Show_List
* ��  �ܣ���������е�Ԫ��
* ��  �Σ�Linklist *L�����в���������
* ����ֵ����
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


