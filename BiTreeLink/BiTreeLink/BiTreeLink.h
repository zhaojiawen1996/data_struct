#ifndef __BITREELINK_H__
#define __BITREELINK_H__

#define MAXSIZE  20

typedef char TElemType;
typedef unsigned char Status;
typedef char string[MAXSIZE];

typedef struct BiTNode
{
	TElemType data;/*���д洢��Ԫ��*/
	struct BiTNode *lchild,*rchild;/*���Һ���ָ��*/
}BiTNode,*BiTree;

#define   Nil     ' '
#define   OK      1
#define   ERROR   0
#define   FALSE   0
#define   TRUE    1

Status CreatBiTreePre(BiTree *T);
Status DestroyBiTree(BiTree *T);
Status InitBiTree(BiTree *T);
void PreTraverse(BiTree T);
void InTraverse(BiTree *T);
void PostOrder(BiTree *T);
int BiTreeDepth(BiTree T);
Status BiTreeEmpty(BiTree T);
TElemType Root(BiTree T);

#endif