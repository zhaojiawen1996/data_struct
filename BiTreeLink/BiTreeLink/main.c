#include "BiTreeLink.h"
#include "stdio.h"
#include "stdlib.h"


int main(void)
{
	BiTree T;
	TElemType e;
	InitBiTree(&T);
	printf("请输入二叉树的元素:\n");
	CreatBiTreePre(&T);
	printf("构造二叉树后，树空否？%d(1是空 0是非空)，树的深度为%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e = Root(T);
	printf("二叉树的根为：%c\n",e);
	printf("前序遍历二叉树的值：\n");
	PreTraverse(T);
	printf("中序遍历二叉树的值：\n");
	InTraverse(&T);
	printf("后序遍历二叉树的值：\n");
	PostOrder(&T);
	DestroyBiTree(&T);
	printf("清除二叉树后，树空否？%d(1是空 0是非空)，树的深度为%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e = Root(T);
	if(!e)
		printf("树空，无根\n");
}