#include "Strings.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

string T;

int main(void)
{
	char * chars= "LOVE ";
	string S1;
	string S2;
	string S3;
	string Sub;
	int position;
	int value;
#if 0
	char * a;
	a = (char *)malloc(sizeof(char));
	printf("%c\n",a[0]);
#endif
	StrAssign(S1,"ILOVEYOULOVEME");
	StrAssign(S2,"LOVE");
	StrAssign(S3,"DING");
	position = Index(S1,S2,3);
	printf("The position is %d\n",position);
	StrPrint(S1);
	//value = StrCompare(S1,S2);
	//printf("The value is :%d\n",value);
	//StrPrint(S2);
	//StrPrint(T);
	//ClearString(T);
	//Concat(T,S1,S2);
	//StrPrint(T);
	//SubString(Sub,T,2,5);
	//StrPrint(Sub);
	Replace(S1,S2,S3);
	StrPrint(S1);
	//StrDelete(S1,3,4);
	//StrPrint(S1);
	StrIncert(S1,4,S3);
	StrPrint(S1);
}