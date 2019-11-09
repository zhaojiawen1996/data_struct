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
	/*注意，静态链表非空时，最后一个元素的游标不一定是1，
	当有新的数据插入到静态链表中，且插入的位置是1时，最
	后一个元素的游标将不是1，此处因为是创建链表，所以为1。*/
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
#if 1
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
#else
/*
*****************************************************************
* 函数名：Length_StaticLink
* 功  能：计算静态链表的长度（遍历静态链表的方法）
* 形  参：StaticLink L：要进行操作的链表
* 返回值：静态链表的长度
*****************************************************************
*/
int Length_StaticLink(StaticLink L)
{
	int i,j;
	i = L[MAXSIZE - 1].cur;/*最后一个元素存放有数值的元素的下标*/
	j = 0;
	while (i)
	{
		i = L[i].cur;
		j++;
	}
	return j;
}

#endif



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
#if 0
/*下述代码插入元素存在错误，当链表处于刚创建好，也就是还没有插入过新元素之前，能够正确插入元素*/
/*但是当链表中已经插入过元素，往链表中再次插入元素时，下述操作将造成错误*/
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
#elif 0 
/*下述代码存在错误，不能实现将新元素插入到第一个元素的功能*/
int Incert_StaticList(StaticLink L, ElemType value, int position)
{
	int i,j,k;
	k = MALLOC_SLL(L);
	j = L[MAXSIZE - 1].cur;
	if (position < 1 || position > k)
	{
		return ERROR;
	}
	for (i = 1;i < position-1;i++)
	{
		j = L[j].cur;/*循环结束，j便是插入元素的上一个元素的游标*/
	}
	L[k].data = value;
	L[k].cur = L[j].cur;
	L[j].cur = k;
	L[0].cur = k + 1;
}

#else
int Incert_StaticList(StaticLink L, ElemType value, int position)
{
	int i, j, k;
	j = MAXSIZE - 1;
	k = MALLOC_SLL(L);
	for (i = 1;i < position;i++)
	{
		j = L[j].cur;/*当循环结束时，此时的j是要插入元素的上一个元素的游标，也就是要插入位置的下标*/
	}
	L[k].data = value;
	L[k].cur = L[j].cur;
	L[j].cur = k;
	//L[0].cur = k + 1;/*在获取空闲分量下标的同时，已经将首个元素的游标值更新*/
	return OK;
}

#endif 

/*
******************************************************
* 函数名：Free_SSL
* 功  能：重新赋值当前位置的游标
* 形  参：StaticLink L：要进行操作的链表
int position：要进行释放的位置
* 返回值：空
*****************************************************
*/
void Free_SSL(StaticLink L, int position)
{
	L[position].cur = L[0].cur;
	L[0].cur = position;
}

/*
*******************************************************
* 函数名：DeletList
* 功  能：删除元素
* 形  参：StaticLink L：要进行操作的链表
          int position：要进行删除元素的位置
* 返回值：操作的状态
*******************************************************
*/
Status DeletList(StaticLink L, int position)
{
	int i,j,k;
	k = MAXSIZE - 1;
	for (i = 1;i < position;i++)
	{
		k = L[k].cur;/*此时的k是要删除的元素的上一个元素的游标，也就是要删除元素的下标*/
	}
	j = L[k].cur;/*j是要删除元素位置的游标*/
	L[k].cur = L[j].cur;/*将要删除元素位置的前一个的游标指向要删除元素位置的下一个*/
	Free_SSL(L,j);
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
#if 0
/*下述代码存在错误，当第一个元素下标不是1时，不能输出第一个元素*/
void Print_Static_Link(StaticLink L)
{
    int i = 1;
	while (i)
	{
		printf("%d\n", L[i].data);
		i = L[i].cur;
	}
}

#else
void Print_Static_Link(StaticLink L)
{
	int i = MAXSIZE - 1;
	i = L[i].cur;
	while (i)
	{
		printf("%d\n", L[i].data);
		i = L[i].cur;
	}
}

#endif