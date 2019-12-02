#include "KMP.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
*********************************************
* 函数名：get_next
* 功  能：生成next数组
* 形  参：string T：模式串
          int *next：要生成的next数组
* 返回值：空
*********************************************
*/
void get_next(string T,int *next)
{
    int i = 1;
	int j = 0;
	next[1] = 0;
	while(i < T[0])/*T[0]是串T的长度*/
	{
	    if(j == 0 || T[i] == T[j])
		{
		    i++;/*串S的索引*/
			j++;/*模式串的索引*/
			next[i] = j; 
		}
		else
		{
			j = next[j];/*j值进行回溯*/
		}
	}
}

/*
************************************************
* 函数名：StrAssign
* 功  能：生成一个其值等于字符串常量chars的串T
* 形  参：string T:    要生成的字符串
          char *chars：已有的字符串
* 返回值：OK or ERROR
************************************************
*/
Status StrAssign(string T,char *chars)
{
    int i;
	if(strlen(chars) > MAXSIZE)
	{
		printf("The chars is ERROR");
	    return ERROR;
	}
	T[0] = strlen(chars);/*字符串的首个元素用于存放字符串的长度*/
	for(i = 1;i <= T[0];i++) 
	{
	    T[i] = *(chars + i - 1);
	}
	return OK;
}

/*
******************************************************
* 函数名：Index_KMP
* 功  能：利用KMP算法返回主串S中pos个位置之后与T串匹配的位置。
* 形  参：string S：要匹配的主串
          string T: 被匹配的模式串
		  int pos ：位置
* 返回值：主串中对应的位置
******************************************************
*/
int Index_KMP(string S,string T,int pos)
{
    int i = pos;/*主串的下标，因为是从pos位置开始寻找，因此将pos值赋值给i*/
	int j = 1;/*模式串的下标*/
	int next[10];/*此处next的下标根据模式串的长度进行设定，对于嵌入式系统，不宜设置过大，以免堆栈溢出*/
	get_next(T,next);
	while(i <= S[0] && j <= T[0])
	{
	    if(j == 0 || S[i] == T[j])
		{
		    j ++;
			i ++;
		}
		else
		{
		    j = next[j];
		}
	}
	if (j > T[0])
	{
	    return i - T[0];
	}
	else
	{
	    return 0;
	}
}

/*
*******************************************************
* 函数名：get_nextval
* 功  能：获取模式串的next数组（改进后的数组）
* 形  参：string T： 模式串
          int *next：要输出的next数组
* 返回值：void
*******************************************************
*/
void get_nextval(string T,int *next)
{
    int i = 1;
	int j = 0;
	next[1] = 0;
	while(i < T[0])
	{
	    if(j == 0 || T[i] == T[j])
		{
		    i ++;
			j ++;
			if(T[i] != T[j])
			{
			    next[i] = j;
			}
			else
			{
			    next[i] = next[j];
			}
		}
		else
		{
		    j = next[j];/*j值进行回溯*/
		}
	}
}