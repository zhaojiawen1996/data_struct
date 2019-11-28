#ifndef __STRINGS_H__
#define __STRINGS_H__

#define MAXSIZE  40 /*定义的字符串所能存储的最大容量*/

#define OK       1
#define ERROR    0

#define TRUE     1
#define FALSE    0

typedef unsigned char Status;
typedef char string[MAXSIZE + 1];

Status StrAssign(string T,char *chars);
Status StrPrint(string T);
Status StrCope(string T,string S);
Status StringEmpty(string T);
Status ClearString(string T);
Status Concat(string T,string S1,string S2);
Status SubString(string Sub,string S,int pos,int len);
int Index(string S,string T,int pos);
int StrCompare(string S,string T);
Status Replace(string S,string T,string V);
Status StrDelete(string S,int pos,int length);
Status StrIncert(string S,int pos,string T);


#endif