#include "KMP.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

string T,S;



int main(void)
{
	int next[20];
	int i;
	int position;

	StrAssign(T,"aaaaaaaab");
	StrAssign(S,"abxabcabxd");
	position = Index_KMP(S,T,3);
	printf("The position is:%d\n",position);
	get_nextval(T,next);
	for(i = 1;i <= T[0];i ++)
	{
	    printf("%d\n",next[i]);   
	}
}