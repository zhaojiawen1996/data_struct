#ifndef __BITHRTREE_H__
#define __BITHRTREE_H__

typedef enum
{
    link,   /*link = 0ָ��������Һ���*/
	Thread  /*Thread = 1ָ�����ǰ������*/
}PointerTag;

typedef char TElemType;
typedef unsigned char Status;

#define    OK           1
#define    ERROR        0
#define    Nil          '#'

typedef struct BiThrNode
{
    TElemType data;/*��������*/
	struct BiThrNode *rchild,*lchild;
	PointerTag RTag;
	PointerTag LTag;
}BiThrNode,*BiThrTree;

void CreatBiTree(BiThrTree *T);
void InThreading(BiThrTree P);
Status InOrderTraverse(BiThrTree T);
Status InOrderThreading(BiThrTree *Thr,BiThrTree T);


#endif