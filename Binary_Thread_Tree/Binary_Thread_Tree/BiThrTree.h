#ifndef __BITHRTREE_H__
#define __BITHRTREE_H__

typedef enum
{
    link,   /*link = 0指向结点的左右孩子*/
	Thread  /*Thread = 1指向结点的前驱或后继*/
}PointerTag;

typedef char TElemType;
typedef unsigned char Status;

#define    OK           1
#define    ERROR        0
#define    Nil          '#'

typedef struct BiThrNode
{
    TElemType data;/*结点的数据*/
	struct BiThrNode *rchild,*lchild;
	PointerTag RTag;
	PointerTag LTag;
}BiThrNode,*BiThrTree;

void CreatBiTree(BiThrTree *T);
void InThreading(BiThrTree P);
Status InOrderTraverse(BiThrTree T);
Status InOrderThreading(BiThrTree *Thr,BiThrTree T);


#endif