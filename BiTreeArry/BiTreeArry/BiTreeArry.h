#ifndef __BITREEARRY_H__
#define __BITREEARRY_H__

#define    OK       1
#define    ERROR    0
#define    TRUE     1
#define    FALSE    0

#define    MAX_TREE_SIZE   30/*���������������*/

#define    Nil      ' '/*����Ϊ�ո�*/

#define    BiTree_Init    ClearTree

typedef struct
{
    int level;/*��ǰ������ڵĲ�*/
	int order;/*��ǰ������ڲ�����*/
}position;

typedef unsigned char Status;
typedef char TElemType;
typedef char BiTree[MAX_TREE_SIZE];/*0�ŵ�Ԫ�洢�����*/ 

Status BiTree_Init(BiTree T);
Status Creat_BiTree(BiTree T);
Status BiTreeEmpty(BiTree T);
int BiTreeDepth(BiTree T);
Status root(BiTree T,TElemType *value);
Status Assign(BiTree T,position pos,TElemType value);
TElemType parent(BiTree T,TElemType value);
TElemType Leftchild(BiTree T,TElemType value);
TElemType Rightchild(BiTree T,TElemType value);
TElemType LeftSlibing(BiTree T,TElemType value);
TElemType RightSlibing(BiTree T,TElemType value);
void PreTraverse(BiTree T,int i);
void InTraverse(BiTree T,int i);
void PostTraverse(BiTree T,int i);
void LevelOrderTraverse(BiTree T);
TElemType value(BiTree T,position pos);
void Print(BiTree T);
void PreOrderTraverse(BiTree T);
#endif