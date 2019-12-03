#include "middle_pointer.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
//#include "ctype.h"
/*
*****************************************************
* ������:Incert_Tail
* ��  �ܣ�����β�巨����һ������Ϊn������
* ��  �Σ�Linked_List* L��Ҫ����������
          int count��Ҫ�����Ľڵ����
* ����ֵ��OK or ERROR
*****************************************************
*/
Status Incert_Tail(Linked_List* L,int count)
{
	Linked_List P,Q;
	int i;
	srand(time(0));
	(*L) = (Linked_List)malloc(sizeof(Node));/*Ϊͷ�������ڴ�ռ�*/
	Q = (Linked_List)malloc(sizeof(Node));
	Q = (*L);
	for(i = 0;i < count;i++)
	{
	    P = (Linked_List)malloc(sizeof(Node));
		P->data = rand()%100 + 1;/*�������100���ڵ���*/
		P->next = NULL;
	    Q->next = P; 
		Q = P;
	}
	return OK;
}


/*
**************************************************
* ��������Print_List
* ��  �ܣ��������е�Ԫ�����
* ��  �Σ�Linked_List L:Ҫ���������
* ����ֵ����
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
* ��������Middle_Pointer
* ��  �ܣ����������м�ڵ��Ԫ�����
* ��  ��: Linked_List L��Ҫ���в���������
          int *value�����ڴ洢�����������
* ����ֵ��OK or ERROR
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