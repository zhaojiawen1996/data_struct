#include "sqlist.h"
#include "stdio.h"
#include "string.h"

/*
**********************************************************
* ��������Incert_Elem
* ��  �ܣ���ԭ�ȵ����Ա��в���һ��Ԫ��
* ��  �Σ�Sqlist *L�����в��������Ա�
          int position��Ҫ�����λ��  
		  ElemType value��Ҫ�����Ԫ��
* ����ֵ��������״̬
**********************************************************
*/
Status Incert_Elem(Sqlist *L,int position,ElemType value)
{
	int i;
	if(position < 1 || position > L->length+1)
	{
		printf("The incert position is error\n");
		return ERROR;
	}
	if(L->length > Maxsize)
	{
		printf("ERROR\n");
		return ERROR;
	}
	for(i = L->length;i >= position;i --)
	{
		L->data[i] = L ->data[i-1];
	}
	L->data[position - 1] = value;
	L->length++;
	return OK;
}


/*
***********************************************************
* ��������Delet_Elem
* ��  �ܣ�ɾ�����Ա��е�һ��Ԫ��
* ��  �Σ�Sqlist *L:���в��������Ա�
          int position������ɾ��Ԫ�ص�λ��
		  ElemType *value�����д洢ɾ����Ԫ��
* ����ֵ��
************************************************************
*/
Status Delet_Elem(Sqlist *L,int position,ElemType *value)
{
    int i;
	if(position < 1 || position > L->length)
	{
	    printf("The Incert position is ERROR");
		return ERROR; 
	}
	if(L->length == 0)
	{
		printf("The List is empty\n");
	    return ERROR;
	}
	*value = L->data[position-1];
	for(i = position;i < L->length;i++)
	{
		L->data[i-1] = L->data[i];
	}
	L->length --;
	return OK;
}


/*
********************************************************************
* ��������List_Init
* ��  �ܣ���ʼ��һ�����Ա�ָ�����Ա�ĳ̶ȣ������Ա��Ԫ�س�ʼ��Ϊ0
* ��  �Σ�Sqlist *L��Ҫ���г�ʼ�������Ա�
          int size:  ���Ա�ĳ���
* ����ֵ��
***********************************************************
*/
Status List_Init(Sqlist *L,int size)
{
	int i;
	for(i = 0;i < size;i++)
	{
		L->data[i] = 0;
	}
	L->length = size;
	return OK;
}


/*
********************************************************
* ��������ListEmpty
* ��  �ܣ��ж�һ�����Ա��Ƿ�Ϊ��
* ��  �Σ�Sqlist L��Ҫ�����жϵ����Ա�
* ����ֵ��������ֵΪTRUE,���Ա�Ϊ��
********************************************************
*/
Status ListEmpty(Sqlist L)
{
	if(L.length == 0)
	{
		return TRUE;
	}
	if(L.length)
	{
		return FALSE;
	}
}

/*
*******************************************************
* ��������ClearList
* ��  �ܣ����һ������
* ��  �Σ�Sqlist *L
* ����ֵ�������Ƿ�ɹ�
*******************************************************
*/
Status ClearList(Sqlist *L)
{
	memset(L->data,0,sizeof(L->data));
	L->length = 0;
	return OK;
}

/*
********************************************************
* ��������GetElem
* ��  �ܣ���ȡ�ض�λ�õ�����
* ��  �Σ�Sqlist L��       ���ҵ�����
          int position��   Ҫ���ҵ�λ��
		  ElemType *value���洢���ҵ���Ԫ��
* ����ֵ��
********************************************************
*/
Status GetElem(Sqlist L,int position,ElemType *value)
{
	if(position < 1 || position > L.length)
	{
	    printf("The position is error");
		return ERROR;
	}
	*value = L.data[position - 1];
	return OK;
}


/*
****************************************************
* ��������LocateElem
* ��  �ܣ��жϸ�����Ԫ���Ƿ������Ա������е�Ԫ�����ظ�
* ��  �Σ�Sqlist L��      ���е����Ա�
          ElemType value��Ҫ���бȽϵ�����
* ����ֵ�����ؼ٣�����һ�£������棬����һ��
****************************************************
*/
Status LocateElem(Sqlist L,ElemType value)
{
	int i;
	if(0 == L.length)
	{
		printf("The List is Empty");
	    return ERROR;
	}
	for(i = 0;i < L.length;i++)
	{
		if(L.data[i] == value)
		{
			return ERROR;
		}
	}
	return OK;
}

