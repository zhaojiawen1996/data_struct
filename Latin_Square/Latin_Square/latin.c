/*
************************************************************************
* �ļ�����latin.c
* ��  �ߣ�wenzi
* ��  �ڣ�2019/12/4
* ��  ����V1.0
*************************************************************************
*/

#include "latin.h"
#include "stdio.h"
#include "stdlib.h"

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
    printf("Please Input the size of the square:\n");
	scanf("%d",&(L->count));
	L->head->next = (Linked_List)malloc(sizeof(sqlist));
	L->head->next->data = L->count;/*�����ĸ���������Ϊһ����㣬��Ϊͷ����������ĵ�һ�����*/ 
	Q = L->head->next;
	for(i = 1;i <= L->count;i++)
	{
	    P = (Linked_List)malloc(sizeof(sqlist));
		P->data = i;
		Q->next = P;
		Q = P;
	}
	Q->next = L->head->next->next;/*β��ָ��ͷ������һ�����*/
	return OK; 
}

/*
****************************************************
* ��������Print_Square
* ��  �ܣ������������
* ��  ��:LinkedList L:������ݵ�����
* ����ֵ��OK or ERROR
****************************************************
*/
Status Print_Square(LinkedList L)
{
    int i,j;
	Linked_List P,Q;
	P = (Linked_List)malloc(sizeof(sqlist));
	P = L.head->next->next;/*ͷָ���һ��ָ��ͷ��㣬ͷ�����������Ž��ĸ���*/
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
