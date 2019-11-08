#include "Static_Linked_List.h"

/*
*****************************************************
* 函数名：InitLink
* 功  能：初始化一个静态链表，将第一个元素的游标指向
          第一个备用链表的下标，因为此时链表为空。将
		  最后一个元素的游标指向第一个元素的下标（0），
		  当链表不为空时，将最后一个元素的游标指向第
		  一个有数据的元素的下标。
* 形  参：StaticLink L：要进行初始化的静态链表
* 返回值：初始化的状态：OK or ERROR
*****************************************************
*/
Status	InitLink(StaticLink L)
{
    int i;
	for(i = 0;i < MAXSIZE - 1;i++)
	{
		L[i].cur = i+1;
	}
	L[i].cur = 0;
	return OK; 
}

/*
*********************************************************************
* 函数名：MALLOC_SLL
* 功  能：返回备用链表中第一个元素的下标，根据静态链表中存储原则，第
          一个元素的游标存放的便是备用链表中第一个元素的下标。在获取到
		  备用链表的下标后，如何此下标不为0，要讲第一个元素的游标值进行
		  更新，使其指向备用链表的第一个元素指向的元素的下标。
* 形  参：StaticLink L：进行操作的链表
* 返回值：备用链表中第一个元素的下标
********************************************************************
*/

#if 1
int MALLOC_SLL(StaticLink L)
{
    int i;
	i = L[0].cur;
	if(L[0].cur)
	{
		L[0].cur = L[i].cur;
	}
	return i;
}

#else 

int MALLOC_SLL(component *L)
{
    int i;
	i = L[0].cur;
	if(L[0].cur)
	{
		L[0].cur = L[i].cur;
	}
	return i;
}

#endif


/*
***************************************************************************
* 函数名：Creat_Static_List
* 功  能:创建一个已知长度的静态链表，首先获取一次静态链表的空闲分量，然后将
         数据插入到空闲分量的位置，插入完之后再获取一次，继续插入
* 形  参：StaticLink L：要创建的链表
          int length  ：长度
		  int value   ：要插入链表的数据
* 返回值：空闲分量的下标
***************************************************************************
*/
#if 1
int Creat_Static_List(StaticLink L,int length,int value)
{
    int Subscript;
	int i;
	//Subscript = MALLOC_SLL(L);
	for(i = 0;i < length;i++)
	{
		Subscript = MALLOC_SLL(L); 
		L[Subscript].data = value + i;
	}
	L[Subscript].cur = 0;
	L[MAXSIZE-1].cur = 1;
	return Subscript; 
}

#else

int Creat_Static_List(component *L,int length,int value)
{
    int Subscript;
	int i;
	Subscript = MALLOC_SLL(L);
	for(i = 0;i < length;i++)
	{
		L[Subscript].data = value + i;
		Subscript = MALLOC_SLL(L); 
	}
	return Subscript; 
}

#endif


/*
*****************************************************************
* 函数名：Length_StaticLink
* 功  能：计算静态链表的长度（根据第一个元素的游标来确定）
* 形  参：StaticLink L：要进行操作的链表
* 返回值：静态链表的长度
*****************************************************************
*/
int Length_StaticLink(StaticLink L)
{
    int Subcript;
	Subcript = MALLOC_SLL(L);
	/*在进行获取空闲分量下标的操作之后，
	如果不进行插入元素的操作，则需要将
	首元素的游标重新赋值*/
	L[0].cur = Subcript; 
	return (Subcript - 1); 
}

/*
****************************************************************
* 函数名：Incert_StaticList
* 功  能：往静态链表中插入一个元素
* 形  参：StaticLink L   ：要进行操作的链表
          ElemType value ：要插入的元素
		  int position   : 插入的位置
* 返回值：返回的状态
*****************************************************************
*/
int Incert_StaticList(StaticLink L,ElemType value,int position)
{
    int i;
	i = Length_StaticLink(L);
	if(position < 1 || position > i+1 || position >= MAXSIZE)
	{
	    return ERROR;
	}
	L[i+1].data = value;
	if(position == i+1)
	{
		L[i+1].cur = 0;
	}
	L[position-1].cur = i+1;
	L[i+1].cur = position;/*就算插入一个元素，下标的位置仍然不发生改变*/
	L[0].cur = i+2;
	return OK;
}

/*
*******************************************************************
* 函数名：Print_Static_Link
* 功  能：根据游标输出静态链表的长度
* 形  参：StaticLink L
* 返回值：无
*******************************************************************
*/
#if 1
void Print_Static_Link(StaticLink L)
{
    int i = 1;
	while (i)
	{
		printf("%d\n", L[i].data);
		i = L[i].cur;
	}
}

#endif