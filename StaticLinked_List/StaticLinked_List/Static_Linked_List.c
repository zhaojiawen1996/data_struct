#include "Static_Linked_List.h"

/*
*****************************************************
* ��������InitLink
* ��  �ܣ���ʼ��һ����̬��������һ��Ԫ�ص��α�ָ��
          ��һ������������±꣬��Ϊ��ʱ����Ϊ�ա���
		  ���һ��Ԫ�ص��α�ָ���һ��Ԫ�ص��±꣨0����
		  ������Ϊ��ʱ�������һ��Ԫ�ص��α�ָ���
		  һ�������ݵ�Ԫ�ص��±ꡣ
* ��  �Σ�StaticLink L��Ҫ���г�ʼ���ľ�̬����
* ����ֵ����ʼ����״̬��OK or ERROR
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
* ��������MALLOC_SLL
* ��  �ܣ����ر��������е�һ��Ԫ�ص��±꣬���ݾ�̬�����д洢ԭ�򣬵�
          һ��Ԫ�ص��α��ŵı��Ǳ��������е�һ��Ԫ�ص��±ꡣ�ڻ�ȡ��
		  ����������±����δ��±겻Ϊ0��Ҫ����һ��Ԫ�ص��α�ֵ����
		  ���£�ʹ��ָ��������ĵ�һ��Ԫ��ָ���Ԫ�ص��±ꡣ
* ��  �Σ�StaticLink L�����в���������
* ����ֵ�����������е�һ��Ԫ�ص��±�
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
* ��������Creat_Static_List
* ��  ��:����һ����֪���ȵľ�̬�������Ȼ�ȡһ�ξ�̬����Ŀ��з�����Ȼ��
         ���ݲ��뵽���з�����λ�ã�������֮���ٻ�ȡһ�Σ���������
* ��  �Σ�StaticLink L��Ҫ����������
          int length  ������
		  int value   ��Ҫ�������������
* ����ֵ�����з������±�
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
* ��������Length_StaticLink
* ��  �ܣ����㾲̬����ĳ��ȣ����ݵ�һ��Ԫ�ص��α���ȷ����
* ��  �Σ�StaticLink L��Ҫ���в���������
* ����ֵ����̬����ĳ���
*****************************************************************
*/
int Length_StaticLink(StaticLink L)
{
    int Subcript;
	Subcript = MALLOC_SLL(L);
	/*�ڽ��л�ȡ���з����±�Ĳ���֮��
	��������в���Ԫ�صĲ���������Ҫ��
	��Ԫ�ص��α����¸�ֵ*/
	L[0].cur = Subcript; 
	return (Subcript - 1); 
}

/*
****************************************************************
* ��������Incert_StaticList
* ��  �ܣ�����̬�����в���һ��Ԫ��
* ��  �Σ�StaticLink L   ��Ҫ���в���������
          ElemType value ��Ҫ�����Ԫ��
		  int position   : �����λ��
* ����ֵ�����ص�״̬
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
	L[i+1].cur = position;/*�������һ��Ԫ�أ��±��λ����Ȼ�������ı�*/
	L[0].cur = i+2;
	return OK;
}

/*
*******************************************************************
* ��������Print_Static_Link
* ��  �ܣ������α������̬����ĳ���
* ��  �Σ�StaticLink L
* ����ֵ����
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