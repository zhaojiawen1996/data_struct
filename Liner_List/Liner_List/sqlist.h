#ifndef __SQLIST_H__
#define __SQLIST_H__

#define Maxsize 20

#define ERROR   0
#define OK      1

#define TRUE    1
#define FALSE   0

typedef int ElemType;
typedef unsigned char Status;

typedef struct
{
  int length;
  ElemType data[Maxsize];
}Sqlist;

Status Incert_Elem(Sqlist *L,int position,ElemType value);
Status Delet_Elem(Sqlist *L,int position,ElemType *value);
Status List_Init(Sqlist *L,int size);
Status ListEmpty(Sqlist L);
Status ClearList(Sqlist *L);
Status GetElem(Sqlist L,int position,ElemType *value);
Status LocateElem(Sqlist L,ElemType value);

#endif