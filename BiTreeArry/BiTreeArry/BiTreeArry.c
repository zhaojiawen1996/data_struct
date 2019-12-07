#include "BiTreeArry.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"


/*
**********************************************************
* 函数名：BiTree_Init
* 功  能：初始化二叉树中的元素，将二叉树中的元素赋值为空
* 形  参：BiTree T：要初始化的二叉树对象
* 返回值：OK or ERROR
**********************************************************
*/
Status BiTree_Init(BiTree T)
{
    int i;
	for(i = 0;i < MAX_TREE_SIZE;i++)
	{
	    T[i] = Nil;/*将分配给树的内存空间全部初始化为Nil*/
	}
	return OK;
}

/*
**********************************************************
* 函数名：Creat_BiTree
* 功  能：创建二叉树，给二叉树中的各个元素赋值
* 形  参：BiTree T：要创建的二叉树对象
* 返回值：OK or ERROR
**********************************************************
*/
Status Creat_BiTree(BiTree T)
{
	int l,i;
	char s[20];
	printf("请按照层序输入结点的值，空格表示的是空结点，结点数<=%d\n",MAX_TREE_SIZE);
	gets(s);
	l = strlen(s);
	for(i = 0;i < l;i++)
	{
	    T[i] = s[i];
		if(T[i] != Nil && T[(i+1)/2-1] == Nil && i != 0)
		{
		    printf("出现无双亲且不是根的结点\n");
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
* 函数名：BiTreeEmpty
* 功  能：判断二叉树是否为空
* 形  参：BiTree T：要判断的二叉树对象
* 返回值：TRUE or FALSE
**********************************************************
*/
Status BiTreeEmpty(BiTree T)
{
    if(T[0] == Nil)
	{
		printf("树为空\n");
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}


/*
**********************************************************
* 函数名：BiTreeDepth
* 功  能：计算二叉树的深度
* 形  参：BiTree T：要计算的二叉树对象
* 返回值：二叉树的深度
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
* 函数名：root
* 功  能：返回二叉树的根结点给value
* 形  参：BiTree T：要计算的二叉树对象
          TElemType *value:存储二叉树的根结点
* 返回值：OK or ERROR
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
* 函数名：value
* 功  能：返回第level层序号为order的结点的值
* 形  参：BiTree T：要操作的树
          position pos：返回数值的序号
* 返回值：结点值
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
		return T[(int)powl(2,pos.level-1)-2+pos.order];/*-1是因为第i层以上的结点数要减1，再减一是因为结点序号是从0开始的*/
	}
}

/*
**********************************************************
* 函数名：Assign
* 功  能：给树中的特点位置的结点赋值
* 形  参：BiTree T：       要进行操作的树
          position pos：   要进行插入数据的结点
		  TElemType value：要插入的数据
* 返回值：OK or ERROR
*********************************************************
*/
Status Assign(BiTree T,position pos,TElemType value)
{
    int i;
	i = (int)powl(2,pos.level-1)-2+pos.order;
	if(value != Nil && T[(i+1)/2-1] == Nil)
	{
	    return ERROR;/*其双亲结点为空*/
	}
	else if(value == Nil && (T[i*2+1] != Nil || T[i*2+2] != Nil)) 
	{
	    return ERROR;/*给双亲赋空值，但是其叶子结点不为空*/
	}
	T[i] = value;
	return OK;
}

/*
********************************************************
* 函数名：parent
* 功  能：找到指定元素的双亲
* 形  参：BiTree T：       要进行操作的二叉树
          TElemType value：要进行匹配的数值
* 返回值：双亲结点的值
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
* 函数名: Leftchild
* 功  能：寻找结点的左孩子
* 形  参：BiTree T：       要进行操作的二叉树
          TElemType value：要进行匹配的数值
* 返回值：结点的左孩子值
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
		    return T[i*2+1];/*匹配到数据之后，返回结点的左孩子*/
		}
	}
	return Nil;/*遍历结束，仍然没有匹配的结点*/
}

/*
********************************************************
* 函数名: Leftchild
* 功  能：寻找结点的左孩子
* 形  参：BiTree T：       要进行操作的二叉树
          TElemType value：要进行匹配的数值
* 返回值：结点的左孩子值
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
		    return T[i*2+2];/*匹配到数据之后，返回结点的左孩子*/
		}
	}
	return Nil;/*遍历结束，仍然没有匹配的结点*/
}


/*
***********************************************************
* 函数名：LeftSlibing
* 功  能：寻找结点的左兄弟
* 形  参：BiTree T：        要匹配的结点
          TElemType value： 要匹配的数值
* 返回值：结点的左兄弟
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
		if(T[i] == value && T[i]%2 == 0)/*匹配到目标结点，且该目标结点是右孩子*/
		{
		    return T[i-1];
		}
	}
}

/*
***********************************************************
* 函数名：RightSlibing
* 功  能：寻找结点的右兄弟
* 形  参：BiTree T：        要匹配的结点
          TElemType value： 要匹配的数值
* 返回值：结点的右兄弟
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
		if(T[i] == value && T[i]%2)/*匹配到目标结点，且该目标结点是左孩子*/
		{
		    return T[i+1];
		}
	}
}


/*
****************************************************
* 函数名：PreTraverse
* 功  能：利用递归算法前序遍历二叉树中的值
* 形  参：BiTree T：要进行操作的二叉树
          int i：二叉树顺序存储的序号
* 返回值：空
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
* 函数名：PreOrderTraverse
* 功  能：利用递归算法前序遍历二叉树中的值
* 形  参：BiTree T：要进行操作的二叉树
          int i：二叉树顺序存储的序号
* 返回值：空
****************************************************
*/
void PreOrderTraverse(BiTree T)
{
    if(!BiTreeEmpty(T))/*二叉树非空*/
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
* 函数名：InTraverse
* 功  能：利用递归算法中序遍历二叉树中的值
* 形  参：BiTree T：要进行操作的二叉树
          int i：   二叉树顺序存储的序号
* 返回值：空
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
* 函数名：InTraverse
* 功  能：利用递归算法中序遍历二叉树中的值
* 形  参：BiTree T：要进行操作的二叉树
          int i：   二叉树顺序存储的序号
* 返回值：空
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
* 函数名：PostTraverse
* 功  能：利用递归算法后序遍历二叉树中的值
* 形  参：BiTree T：要进行操作的二叉树
          int i：   二叉树顺序存储的序号
* 返回值：空
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
* 函数名：PostOrderTraverse
* 功  能：利用递归算法后序遍历二叉树中的值
* 形  参：BiTree T：要进行操作的二叉树
          int i：   二叉树顺序存储的序号
* 返回值：空
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
* 函数名：LevelOrderTraverse
* 功  能：按照层序打印树的非空结点
* 形  参：BiTree T：要遍历的树
* 返回值：空
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
		    printf("%c",T[j]);/*只打印非空结点*/
		}
	}
	printf("\n");
}

/*
******************************************************
* 函数名：Print
* 功  能：按照层序遍历树
* 形  参：BiTree T
* 返回值：空
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
		printf("第%d层",j);
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