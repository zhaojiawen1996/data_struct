#ifndef __PTREE_H__
#define __PTREE_H__

#define      MAXSIZE     50
#define      OK          1
#define      ERROR       0

typedef char ElemType;
typedef char string[MAXSIZE];

/*�������еĽ��*/
typedef struct PTNode
{
	ElemType data;/*����а���������*/
	int parents;/*˫��λ��*/
}PTNode;

/*�������Ľṹ*/
typedef struct PTree
{
    PTNode nodes[MAXSIZE];
    int r,n;/*����λ�úͽ����*/
}PTree;

typedef unsigned char Status;

Status CreateTree(PTree *T);
Status Find_Tree(PTree *T);
Status InitTree(PTree *T);
#endif