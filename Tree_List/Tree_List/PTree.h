#ifndef __PTREE_H__
#define __PTREE_H__

#define      MAXSIZE     50
#define      OK          1
#define      ERROR       0

typedef char ElemType;
typedef char string[MAXSIZE];

/*定义树中的结点*/
typedef struct PTNode
{
	ElemType data;/*结点中包含数据域*/
	int parents;/*双亲位置*/
}PTNode;

/*定义树的结构*/
typedef struct PTree
{
    PTNode nodes[MAXSIZE];
    int r,n;/*根的位置和结点数*/
}PTree;

typedef unsigned char Status;

Status CreateTree(PTree *T);
Status Find_Tree(PTree *T);
Status InitTree(PTree *T);
#endif