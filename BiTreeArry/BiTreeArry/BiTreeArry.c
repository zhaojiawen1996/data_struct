#include "BiTreeArry.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"


/*
**********************************************************
* ��������BiTree_Init
* ��  �ܣ���ʼ���������е�Ԫ�أ����������е�Ԫ�ظ�ֵΪ��
* ��  �Σ�BiTree T��Ҫ��ʼ���Ķ���������
* ����ֵ��OK or ERROR
**********************************************************
*/
Status BiTree_Init(BiTree T)
{
    int i;
	for(i = 0;i < MAX_TREE_SIZE;i++)
	{
	    T[i] = Nil;/*������������ڴ�ռ�ȫ����ʼ��ΪNil*/
	}
	return OK;
}

/*
**********************************************************
* ��������Creat_BiTree
* ��  �ܣ����������������������еĸ���Ԫ�ظ�ֵ
* ��  �Σ�BiTree T��Ҫ�����Ķ���������
* ����ֵ��OK or ERROR
**********************************************************
*/
Status Creat_BiTree(BiTree T)
{
	int l,i;
	char s[20];
	printf("�밴�ղ����������ֵ���ո��ʾ���ǿս�㣬�����<=%d\n",MAX_TREE_SIZE);
	gets(s);
	l = strlen(s);
	for(i = 0;i < l;i++)
	{
	    T[i] = s[i];
		if(T[i] != Nil && T[(i+1)/2-1] == Nil && i != 0)
		{
		    printf("������˫���Ҳ��Ǹ��Ľ��\n");
			return ERROR;
		}
	}
	for(;i < MAX_TREE_SIZE;i++)
	{
	    T[i] = Nil;
	}
	return OK;
}

/*
**********************************************************
* ��������BiTreeEmpty
* ��  �ܣ��ж϶������Ƿ�Ϊ��
* ��  �Σ�BiTree T��Ҫ�жϵĶ���������
* ����ֵ��TRUE or FALSE
**********************************************************
*/
Status BiTreeEmpty(BiTree T)
{
    if(T[0] == Nil)
	{
		printf("��Ϊ��\n");
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


/*
**********************************************************
* ��������BiTreeDepth
* ��  �ܣ���������������
* ��  �Σ�BiTree T��Ҫ����Ķ���������
* ����ֵ�������������
**********************************************************
*/
int BiTreeDepth(BiTree T)
{
    int i,j = -1; 
	for(i = MAX_TREE_SIZE-1;i >= 0;i--)
	{
	    if(T[i] != Nil)
		{
		    break;
		}
	}
	do
	{
 	    j ++;
	}while(i >= powl(2,j)-1);
	return j;
}

/*
**********************************************************
* ��������root
* ��  �ܣ����ض������ĸ�����value
* ��  �Σ�BiTree T��Ҫ����Ķ���������
          TElemType *value:�洢�������ĸ����
* ����ֵ��OK or ERROR
**********************************************************
*/
Status root(BiTree T,TElemType *value)
{
    if(T[0] != Nil)
	{
	    *value = T[0];
	}
	else
	{
		printf("The Tree of the root is empty\n");
	    return ERROR;
	}
	return OK;
}


/*
*******************************************************
* ��������value
* ��  �ܣ����ص�level�����Ϊorder�Ľ���ֵ
* ��  �Σ�BiTree T��Ҫ��������
          position pos��������ֵ�����
* ����ֵ�����ֵ
*******************************************************
*/
TElemType value(BiTree T,position pos)
{
    if(BiTreeEmpty(T))
	{
		printf("The Tree is Empty\n");
	    return ERROR;
	}
	else
	{
		return T[(int)powl(2,pos.level-1)-2+pos.order];/*-1����Ϊ��i�����ϵĽ����Ҫ��1���ټ�һ����Ϊ�������Ǵ�0��ʼ��*/
	}
}

/*
**********************************************************
* ��������Assign
* ��  �ܣ������е��ص�λ�õĽ�㸳ֵ
* ��  �Σ�BiTree T��       Ҫ���в�������
          position pos��   Ҫ���в������ݵĽ��
		  TElemType value��Ҫ���������
* ����ֵ��OK or ERROR
*********************************************************
*/
Status Assign(BiTree T,position pos,TElemType value)
{
    int i;
	i = (int)powl(2,pos.level-1)-2+pos.order;
	if(value != Nil && T[(i+1)/2-1] == Nil)
	{
	    return ERROR;/*��˫�׽��Ϊ��*/
	}
	else if(value == Nil && (T[i*2+1] != Nil || T[i*2+2] != Nil)) 
	{
	    return ERROR;/*��˫�׸���ֵ��������Ҷ�ӽ�㲻Ϊ��*/
	}
	T[i] = value;
	return OK;
}

/*
********************************************************
* ��������parent
* ��  �ܣ��ҵ�ָ��Ԫ�ص�˫��
* ��  �Σ�BiTree T��       Ҫ���в����Ķ�����
          TElemType value��Ҫ����ƥ�����ֵ
* ����ֵ��˫�׽���ֵ
********************************************************
*/
TElemType parent(BiTree T,TElemType value)
{
	int i;
    if(BiTreeEmpty(T))
	{
	    return Nil;
	}
	else
	{
	    for(i = 0;i < MAX_TREE_SIZE;i++)
		{
		    if(T[i] == value)
			{
			    return T[(i+1)/2-1];
			}
		}
        return Nil;
	}
}


/*
********************************************************
* ������: Leftchild
* ��  �ܣ�Ѱ�ҽ�������
* ��  �Σ�BiTree T��       Ҫ���в����Ķ�����
          TElemType value��Ҫ����ƥ�����ֵ
* ����ֵ����������ֵ
********************************************************
*/
TElemType Leftchild(BiTree T,TElemType value)
{
    int i;
	if(BiTreeEmpty(T))
	{
	    return Nil;
	}
	for(i = 0;i < MAX_TREE_SIZE;i++)
	{
	    if(T[i] == value)
		{
		    return T[i*2+1];/*ƥ�䵽����֮�󣬷��ؽ�������*/
		}
	}
	return Nil;/*������������Ȼû��ƥ��Ľ��*/
}

/*
********************************************************
* ������: Leftchild
* ��  �ܣ�Ѱ�ҽ�������
* ��  �Σ�BiTree T��       Ҫ���в����Ķ�����
          TElemType value��Ҫ����ƥ�����ֵ
* ����ֵ����������ֵ
********************************************************
*/
TElemType Rightchild(BiTree T,TElemType value)
{
    int i;
	if(BiTreeEmpty(T))
	{
	    return Nil;
	}
	for(i = 0;i < MAX_TREE_SIZE;i++)
	{
	    if(T[i] == value)
		{
		    return T[i*2+2];/*ƥ�䵽����֮�󣬷��ؽ�������*/
		}
	}
	return Nil;/*������������Ȼû��ƥ��Ľ��*/
}


/*
***********************************************************
* ��������LeftSlibing
* ��  �ܣ�Ѱ�ҽ������ֵ�
* ��  �Σ�BiTree T��        Ҫƥ��Ľ��
          TElemType value�� Ҫƥ�����ֵ
* ����ֵ���������ֵ�
***********************************************************
*/
TElemType LeftSlibing(BiTree T,TElemType value)
{
    int i;
	if(BiTreeEmpty(T))
	{
	    return Nil;
	}
	for(i = 0;i < MAX_TREE_SIZE;i++)
	{
		if(T[i] == value && T[i]%2 == 0)/*ƥ�䵽Ŀ���㣬�Ҹ�Ŀ�������Һ���*/
		{
		    return T[i-1];
		}
	}
}

/*
***********************************************************
* ��������RightSlibing
* ��  �ܣ�Ѱ�ҽ������ֵ�
* ��  �Σ�BiTree T��        Ҫƥ��Ľ��
          TElemType value�� Ҫƥ�����ֵ
* ����ֵ���������ֵ�
***********************************************************
*/
TElemType RightSlibing(BiTree T,TElemType value)
{
    int i;
	if(BiTreeEmpty(T))
	{
	    return Nil;
	}
	for(i = 0;i < MAX_TREE_SIZE;i++)
	{
		if(T[i] == value && T[i]%2)/*ƥ�䵽Ŀ���㣬�Ҹ�Ŀ����������*/
		{
		    return T[i+1];
		}
	}
}


/*
****************************************************
* ��������PreTraverse
* ��  �ܣ����õݹ��㷨ǰ������������е�ֵ
* ��  �Σ�BiTree T��Ҫ���в����Ķ�����
          int i��������˳��洢�����
* ����ֵ����
****************************************************
*/
void PreTraverse(BiTree T,int i)
{
	if(T[i] == Nil)
	{
	    return;
	}
	printf("%c",T[i]);
	PreTraverse(T,2*i+1);
	PreTraverse(T,2*i+2);
}


/*
****************************************************
* ��������PreOrderTraverse
* ��  �ܣ����õݹ��㷨ǰ������������е�ֵ
* ��  �Σ�BiTree T��Ҫ���в����Ķ�����
          int i��������˳��洢�����
* ����ֵ����
****************************************************
*/
void PreOrderTraverse(BiTree T)
{
    if(!BiTreeEmpty(T))/*�������ǿ�*/
	{
	     PreTraverse(T,0);
		 printf("\n");
	}
	else
	{
	    return;
	}
}

/*
****************************************************
* ��������InTraverse
* ��  �ܣ����õݹ��㷨��������������е�ֵ
* ��  �Σ�BiTree T��Ҫ���в����Ķ�����
          int i��   ������˳��洢�����
* ����ֵ����
****************************************************
*/
void InTraverse(BiTree T,int i)
{
    if(T[i] == Nil)
	{
	    return;
	}
	InTraverse(T,2*i+1);
	printf("%c",T[i]);
	InTraverse(T,2*i+2);
}


/*
****************************************************
* ��������InTraverse
* ��  �ܣ����õݹ��㷨��������������е�ֵ
* ��  �Σ�BiTree T��Ҫ���в����Ķ�����
          int i��   ������˳��洢�����
* ����ֵ����
****************************************************
*/
void InOrderTraverse(BiTree T)
{
    if(!BiTreeEmpty(T))
	{
	    InTraverse(T,0);
		printf("\n");
	}
	else
	{
	    return;    
	}
}

/*
****************************************************
* ��������PostTraverse
* ��  �ܣ����õݹ��㷨��������������е�ֵ
* ��  �Σ�BiTree T��Ҫ���в����Ķ�����
          int i��   ������˳��洢�����
* ����ֵ����
****************************************************
*/
void PostTraverse(BiTree T,int i)
{
    if(T[i] == Nil)
	{
	    return;
	}
	PostTraverse(T,2*i+1);
	PostTraverse(T,i*2+2);
	printf("%c",T[i]);
}


/*
****************************************************
* ��������PostOrderTraverse
* ��  �ܣ����õݹ��㷨��������������е�ֵ
* ��  �Σ�BiTree T��Ҫ���в����Ķ�����
          int i��   ������˳��洢�����
* ����ֵ����
****************************************************
*/
void PostOrderTraverse(BiTree T)
{
    if(!BiTreeEmpty(T))
	{
	    PostTraverse(T,0);   
	}
	else
	{
	    return;
	}
}

/*
***********************************************************
* ��������LevelOrderTraverse
* ��  �ܣ����ղ����ӡ���ķǿս��
* ��  �Σ�BiTree T��Ҫ��������
* ����ֵ����
***********************************************************
*/
void LevelOrderTraverse(BiTree T)
{
	int i,j;
	for(i = MAX_TREE_SIZE-1;i >= 0;i--)
	{
	    if(T[i] != Nil)
		{
		    break;
		}
	}
	if(i < 0)
	{
	    printf("This is a empty tree");
		return;
	}
	for(j = 0;j <= i;j++)
	{
		if(T[j] != Nil)
		{
		    printf("%c",T[j]);/*ֻ��ӡ�ǿս��*/
		}
	}
	printf("\n");
}

/*
******************************************************
* ��������Print
* ��  �ܣ����ղ��������
* ��  �Σ�BiTree T
* ����ֵ����
******************************************************
*/
void Print(BiTree T)
{
    int i,j;
	int depth;
	position pos;
	depth = BiTreeDepth(T);
	for(j = 1;j <= depth;j++)
	{
		printf("��%d��",j);
		for(i = 1;i <= powl(2,j-1);i++)
		{
			pos.level = j;
			pos.order = i;
			if(value(T,pos) != Nil)
			{
			    printf("%d:%d",i,value(T,pos));
			}
		}
	}
}