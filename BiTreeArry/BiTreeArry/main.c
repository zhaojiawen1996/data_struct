#include "BiTreeArry.h"
#include "stdio.h"
#include "string.h"

BiTree T;

int main(void)
{
	int depth,i,j;
	TElemType e;
	position pos;
    BiTree_Init(T);
	Creat_BiTree(T);
	printf("建立树后，树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	if(root(T,&e))
	{
	    printf("二叉树的根为：%c\n",e);
	}
	else
	{
	    printf("树空，无根\n");
	}
	printf("层序遍历二叉树:\n");
	LevelOrderTraverse(T);
	printf("前序遍历二叉树:\n");
	PreOrderTraverse(T);
	printf("中序遍历二叉树:\n");
	InTraverse(T,0);
	printf("后序遍历二叉树:\n");
	PostTraverse(T,0);
	printf("请输入要更改的树的层号和序号:\n");
	scanf("%d %d",&i,&j);
	pos.level = i;
	pos.order = j;
	e = value(T,pos);
	printf("待修改的原值为%c,请输入新值：",e);
	fflush(stdin);
	scanf("%c",&e);
	Assign(T,pos,e);
	printf("再次前序遍历二叉树中的元素:\n");
	PreOrderTraverse(T);
	printf("结点为%c的双亲为%c,左右孩子分别为：%c,%c",e,parent(T,e),Leftchild(T,e),Rightchild(T,e));
	printf("左右兄弟为：%c,%c",LeftSlibing(T,e),RightSlibing(T,e));
	ClearTree(T);
	printf("清除二叉树后，树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
    if(root(T,&e))
	{
	    printf("二叉树的根为：%c\n",e);
	}
	else
	{
	    printf("树空，无根\n");
	}
}