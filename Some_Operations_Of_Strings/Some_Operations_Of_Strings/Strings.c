#include "Strings.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

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
*******************************************************
* 函数名：StrPrint
* 功  能：输出字符串
* 形  参：string T：要输出的字符串
* 返回值：OK or ERROR
******************************************************
*/
Status StrPrint(string T)
{
    int i;
	//T[0] = strlen(T);/*用strlen求出的长度包含字符串末尾的‘\0’,所以计算出来的个数会多出一个*/
	printf("The Length Of String is:%d\n",T[0]);
	printf("The String is:\n");
	for(i = 1;i <= T[0];i++)
	{
	    printf("%c",T[i]);
	}
	printf("\n");
	return OK;
}

/*
*******************************************
* 函数名：StrCope
* 功  能：若串S存在，则由串S复制得串T
* 形  参：string T:目标串
          string S:要复制的串
* 返回值：OK or ERROR
*******************************************
*/
Status StrCope(string T,string S)
{
    int i;
	if(S[0] == 0)
	{
	    printf("The string is Empty");
		return ERROR;
	}
	for(i = 0;i < S[0];i++)
	{
	    T[i] = S[i];/*将串S逐个复制到串T*/
	}
	return OK;
}

/*
*******************************************
* 函数名：StringEmpty
* 功  能：判断串是否为空
* 形  参：string T:目标串
* 返回值：如果string为空，则返回TRUE
          如果string非空，则返回FALSE
*******************************************
*/
Status StringEmpty(string T)
{
    if(!T[0])
	{
	    return TRUE;
	}
	else
	{
	    return FALSE;
	}
}

/*
*******************************************
* 函数名：ClearString
* 功  能: 清除串，将串中所有元素清0
* 形  参：string T:目标串
* 返回值：OK or ERROR
*******************************************
*/
Status ClearString(string T)
{
    memset(T,0,sizeof(T));
	return OK;
}

/*
*******************************************
* 函数名：StrLength
* 功  能:返回串的长度
* 形  参：string T：目标串
* 返回值：length
*******************************************
*/
int StrLength(string T)
{
    return T[0];/*返回串T的长度*/
}


/*
*******************************************************
* 函数名：Concat
* 功  能：将S1和S2两个串连接到一个串T并输出
* 形  参：string T：目标串
          string S1：要连接的串1
		  string S2：要连接的串2
* 返回值：OK or ERROR
*******************************************************
*/
Status Concat(string T,string S1,string S2)
{
	int i;
	/*不需要截断，完整的两段*/
	if(S1[0] + S2[0] < MAXSIZE)/*不能加上“=”，因为最终合成的串T中需要有一位保存串的长度 */
	{
	    for(i = 1;i <= S1[0];i++)
		{
		    T[i] = S1[i];/*将S1的复制到T中*/
		}
		for(i = 1;i <= S2[0];i++)
		{
		    T[S1[0] + i] = S2[i];/*将S2的内容复制到T中*/
		}
		T[0] = S1[0] + S2[0];
	}
	/*需要截断，S2的部分被截断，T的容量不够*/
	else
	{
	    for(i = 1;i <= S1[0];i++)
		{
		    T[i] = S1[i];/*将S1的复制到T中*/
		}
		for(i = 1;i < MAXSIZE-S1[0];i++)
		{
		    T[S1[0] + i] = S2[i];
		}
		T[0] = MAXSIZE;
	}
	return OK;
} 

/*
************************************************************
* 函数名：SubString
* 功  能：将串S中从pos的位置开始复制len得长度的字符串到Sub
* 形  参：string Sub:复制字符串存储位置
          string S： 源字符串
		  int pos：  要截取的位置
		  int len：  要截取的长度
* 返回值：OK or ERROR
***********************************************************
*/
Status SubString(string Sub,string S,int pos,int len)
{  
	int i;
    if(S[0])
	{
	    if((StrLength(S) >= pos) && (pos >= 1) && (len >= 0) && (StrLength(S) - (pos - 1) >= len))
		{
		    for(i = 1;i <= len;i++)
			{
			    Sub[i] = S[pos + i - 1];
			}
			Sub[0] = len;
		}
		else
		{
			printf("The S is ERROR");
		    return ERROR;
		}
	}
	else
	{
		printf("The String S is Empty");
	    return ERROR;
	}
	return OK;
}

/*
************************************************************
* 函数名：StrCompare
* 功  能：比较两字符串的大小，若S>T,返回值>0;若S=T，返回值=0
          若S<T,返回值<0
* 形  参：string S: 串1
          string T：串2
* 返回值：比较结果
************************************************************
*/
int StrCompare(string S,string T)
{
    int i;
	for(i = 1;i <= StrLength(S) && i <= StrLength(T);i++)
	{
	    if(S[i] != T[i])
		{
		    return S[i] - T[i];
		}
	}
	return 0;
}
/*
************************************************************
* 函数名：Index
* 功  能：若主串S中第pos个字符之后存在与T相等的字串，
          则返回第一个这样的字串在S中的位置，否则返回0
* 形  参：string S：主串
          string T：子串
		  int pos：主串索引
* 返回值：主串中的位置
***********************************************************
*/
#if 0
int Index(string S,string T,int pos)
{
	int i,j;
	i = pos;
	j = 1;/*从字符串的第1个位置开始索引*/
	while(i <= StrLength(S) && j <= StrLength(T))
	{
	    if(S[i] == T[j])
		{
		    i ++;
			j ++;
		}
		else
		{
		    i = i-j+2;/*退回到上个匹配的首字母的下一个字符*/
			j = 1;/*j回退到1，也就是串T的起始位置*/
		}
	}
	if(j > StrLength(T))
	{
	    return i-j+1;
	}
	else
	{
	    return ERROR;/*没有找到则返回0*/
	}
}
#else 
int Index(string S,string T,int pos)
{
    int i,m,n;
	string Sub;
	if(pos > 0) 
	{
		m = StrLength(S);
		n = StrLength(T);
		i = pos;
		while(i <= m-n+1)
		{
			SubString(Sub,S,i,n);
			if(StrCompare(Sub,T) != 0)
			{
			    i ++;
			}
			else
			{
			    return i;
			}
		}
	}
	return 0;/*若无子串相等，返回0*/
}
#endif

/*
**********************************************************
* 函数名：StrDelete
* 功  能：从S的指定位置删除一段指定长度的串
* 形  参：string S：  目标串
          int pos:    指定的位置
		  int length：要删除的长度
* 返回值：OK or ERROR
**********************************************************
*/
Status StrDelete(string S,int pos,int length)
{
	int i;

    if(StringEmpty(S))
	{
	    printf("The string S is Empty!\n");/*串S是空的*/
		return ERROR;
	}
	else
	{
		if(pos >= 1 && StrLength(S)-length+1 >= pos)
		{
		    for(i = pos;i <= StrLength(S)-length;i++)
			{
			    S[i] = S[i+length]; 
				S[i+length] = 0;   
			}
			S[0] = S[0] - length;
			return OK;
		}
		return ERROR;
	}    
}

/*
***************************************************
* 函数名：StrIncert
* 功  能：往串中插入一个字串
* 形  参：string S：目标串
          int pos： 要插入的位置
		  string T：要插入的字符串
* 返回值：OK or ERROR
**************************************************
*/
Status StrIncert(string S,int pos,string T)
{
    int i;
	if(pos >= 1 && pos <= StrLength(S)+1)
	{
		/*完全插入*/
		if(StrLength(S) + StrLength(T) <= MAXSIZE)
		{
	        for(i = StrLength(S)+StrLength(T);i >= pos+StrLength(T);i--)
	        {
	            S[i] = S[i - StrLength(T)];/*完成移位操作*/
	        }
	        for(i = pos;i < pos+StrLength(T);i++)
	        {
	            S[i] = T[i-pos+1];/*赋值操作*/
	        }
		    S[0] = S[0]+StrLength(T);
	        return OK;		
		}
		/*不完全插入*/
		else
		{
		    for(i = MAXSIZE;i >= pos+StrLength(T);i--)
			{
			    S[i] = S[i - StrLength(T)];
			}
			for(i = pos;i < pos+StrLength(T);i++)
			{
				if(i > MAXSIZE)
				{
				    printf("The incert position plus the length of the data exceeds the maximum\n");
					return ERROR;
				}
			    S[i] = T[i-pos+1];
			}
			S[0] = MAXSIZE;
			return OK;
		}
	}
	else
	{
	    return ERROR;
	}
}

/*
*********************************************************
* 函数名：Replace
* 功  能：如果S中存在和T相等的子串，那么其全部替换为V
* 形  参：string S:目标串
          string T：要查找的串
		  string V：要替换的串
* 返回值：OK or ERROR
*********************************************************
*/

#if 0
Status Replace(string S,string T,string V)
{
    int i;
	int j;
	string Sub;

	i = 1;
	while(i <= StrLength(S))
	{
		if(StrLength(T) != StrLength(V))
		{
			printf("The T and V is unmached!\n");
		    return ERROR;
		}
		SubString(Sub,S,i,StrLength(T));
		if(StrCompare(Sub,T) == 0)
		{
			for(j = 1;j <= StrLength(V);j++)
			{
			    S[j+i-1] = V[j];
			}
			i = i + StrLength(V) + 2;/*+2才能到达新的一位*/
		}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
		else
		{
		    i ++;
		}
	}
	return OK;
}

#else
Status Replace(string S,string T,string V)
{
	int i;

	i = 1;
	if(StrLength(S) == 0 || StrLength(T) == 0 || StrLength(V) == 0)
	{
		printf("There is a empty string in three strings\n");
	    return ERROR;
	}
	else
	{
		do
		{
	        i = Index(S,T,i); 
		    if(i)
		    {
		        StrDelete(S,i,StrLength(T));
			    StrIncert(S,i,V);
		    }		
		}while(i);
		return OK;
	}
}
#endif