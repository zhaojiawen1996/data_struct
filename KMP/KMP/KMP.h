#ifndef __KMP_H__
#define __KMP_H__


typedef unsigned char Status;

#define   MAXSIZE  20
#define   OK       1
#define   ERROR    0

typedef char string[MAXSIZE + 1];

void get_next(string T,int *next);
Status StrAssign(string T,char *chars);
int Index_KMP(string S,string T,int pos);
void get_nextval(string T,int *next);


#endif