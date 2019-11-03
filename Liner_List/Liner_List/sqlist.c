#include "sqlist.h"
#include "stdio.h"
#include "string.h"

/*
**********************************************************
* 函数名：Incert_Elem
* 功  能：在原先的线性表中插入一个元素
* 形  参：Sqlist *L：进行操作的线性表
          int position：要插入的位置  
		  ElemType value：要插入的元素
* 返回值：操作的状态
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
* 函数名：Delet_Elem
* 功  能：删除线性表中的一个元素
* 形  参：Sqlist *L:进行操作的线性表
          int position：进行删除元素的位置
		  ElemType *value：进行存储删除的元素
* 返回值：
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
* 函数名：List_Init
* 功  能：初始化一个线性表，指定线性表的程度，将线性表的元素初始化为0
* 形  参：Sqlist *L：要进行初始化的线性表
          int size:  线性表的长度
* 返回值：
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
* 函数名：ListEmpty
* 功  能：判断一个线性表是否为空
* 形  参：Sqlist L：要进行判断的线性表
* 返回值：当返回值为TRUE,线性表为空
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
* 函数名：ClearList
* 功  能：清空一个链表
* 形  参：Sqlist *L
* 返回值：操作是否成功
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
* 函数名：GetElem
* 功  能：获取特定位置的数据
* 形  参：Sqlist L：       查找的链表
          int position：   要查找的位置
		  ElemType *value：存储查找到的元素
* 返回值：
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
* 函数名：LocateElem
* 功  能：判断给定的元素是否与线性表中已有的元素相重复
* 形  参：Sqlist L：      已有的线性表
          ElemType value：要进行比较的数据
* 返回值：返回假，代表一致，返回真，代表不一致
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

