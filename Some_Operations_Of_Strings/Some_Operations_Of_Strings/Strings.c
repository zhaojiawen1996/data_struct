#include "Strings.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

/*
************************************************
* ��������StrAssign
* ��  �ܣ�����һ����ֵ�����ַ�������chars�Ĵ�T
* ��  �Σ�string T:    Ҫ���ɵ��ַ���
          char *chars�����е��ַ���
* ����ֵ��OK or ERROR
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
	T[0] = strlen(chars);/*�ַ������׸�Ԫ�����ڴ���ַ����ĳ���*/
	for(i = 1;i <= T[0];i++) 
	{
	    T[i] = *(chars + i - 1);
	}
	return OK;
}


/*
*******************************************************
* ��������StrPrint
* ��  �ܣ�����ַ���
* ��  �Σ�string T��Ҫ������ַ���
* ����ֵ��OK or ERROR
******************************************************
*/
Status StrPrint(string T)
{
    int i;
	//T[0] = strlen(T);/*��strlen����ĳ��Ȱ����ַ���ĩβ�ġ�\0��,���Լ�������ĸ�������һ��*/
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
* ��������StrCope
* ��  �ܣ�����S���ڣ����ɴ�S���Ƶô�T
* ��  �Σ�string T:Ŀ�괮
          string S:Ҫ���ƵĴ�
* ����ֵ��OK or ERROR
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
	    T[i] = S[i];/*����S������Ƶ���T*/
	}
	return OK;
}

/*
*******************************************
* ��������StringEmpty
* ��  �ܣ��жϴ��Ƿ�Ϊ��
* ��  �Σ�string T:Ŀ�괮
* ����ֵ�����stringΪ�գ��򷵻�TRUE
          ���string�ǿգ��򷵻�FALSE
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
* ��������ClearString
* ��  ��: �����������������Ԫ����0
* ��  �Σ�string T:Ŀ�괮
* ����ֵ��OK or ERROR
*******************************************
*/
Status ClearString(string T)
{
    memset(T,0,sizeof(T));
	return OK;
}

/*
*******************************************
* ��������StrLength
* ��  ��:���ش��ĳ���
* ��  �Σ�string T��Ŀ�괮
* ����ֵ��length
*******************************************
*/
int StrLength(string T)
{
    return T[0];/*���ش�T�ĳ���*/
}


/*
*******************************************************
* ��������Concat
* ��  �ܣ���S1��S2���������ӵ�һ����T�����
* ��  �Σ�string T��Ŀ�괮
          string S1��Ҫ���ӵĴ�1
		  string S2��Ҫ���ӵĴ�2
* ����ֵ��OK or ERROR
*******************************************************
*/
Status Concat(string T,string S1,string S2)
{
	int i;
	/*����Ҫ�ضϣ�����������*/
	if(S1[0] + S2[0] < MAXSIZE)/*���ܼ��ϡ�=������Ϊ���պϳɵĴ�T����Ҫ��һλ���洮�ĳ��� */
	{
	    for(i = 1;i <= S1[0];i++)
		{
		    T[i] = S1[i];/*��S1�ĸ��Ƶ�T��*/
		}
		for(i = 1;i <= S2[0];i++)
		{
		    T[S1[0] + i] = S2[i];/*��S2�����ݸ��Ƶ�T��*/
		}
		T[0] = S1[0] + S2[0];
	}
	/*��Ҫ�ضϣ�S2�Ĳ��ֱ��ضϣ�T����������*/
	else
	{
	    for(i = 1;i <= S1[0];i++)
		{
		    T[i] = S1[i];/*��S1�ĸ��Ƶ�T��*/
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
* ��������SubString
* ��  �ܣ�����S�д�pos��λ�ÿ�ʼ����len�ó��ȵ��ַ�����Sub
* ��  �Σ�string Sub:�����ַ����洢λ��
          string S�� Դ�ַ���
		  int pos��  Ҫ��ȡ��λ��
		  int len��  Ҫ��ȡ�ĳ���
* ����ֵ��OK or ERROR
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
* ��������StrCompare
* ��  �ܣ��Ƚ����ַ����Ĵ�С����S>T,����ֵ>0;��S=T������ֵ=0
          ��S<T,����ֵ<0
* ��  �Σ�string S: ��1
          string T����2
* ����ֵ���ȽϽ��
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
* ��������Index
* ��  �ܣ�������S�е�pos���ַ�֮�������T��ȵ��ִ���
          �򷵻ص�һ���������ִ���S�е�λ�ã����򷵻�0
* ��  �Σ�string S������
          string T���Ӵ�
		  int pos����������
* ����ֵ�������е�λ��
***********************************************************
*/
#if 0
int Index(string S,string T,int pos)
{
	int i,j;
	i = pos;
	j = 1;/*���ַ����ĵ�1��λ�ÿ�ʼ����*/
	while(i <= StrLength(S) && j <= StrLength(T))
	{
	    if(S[i] == T[j])
		{
		    i ++;
			j ++;
		}
		else
		{
		    i = i-j+2;/*�˻ص��ϸ�ƥ�������ĸ����һ���ַ�*/
			j = 1;/*j���˵�1��Ҳ���Ǵ�T����ʼλ��*/
		}
	}
	if(j > StrLength(T))
	{
	    return i-j+1;
	}
	else
	{
	    return ERROR;/*û���ҵ��򷵻�0*/
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
	return 0;/*�����Ӵ���ȣ�����0*/
}
#endif

/*
**********************************************************
* ��������StrDelete
* ��  �ܣ���S��ָ��λ��ɾ��һ��ָ�����ȵĴ�
* ��  �Σ�string S��  Ŀ�괮
          int pos:    ָ����λ��
		  int length��Ҫɾ���ĳ���
* ����ֵ��OK or ERROR
**********************************************************
*/
Status StrDelete(string S,int pos,int length)
{
	int i;

    if(StringEmpty(S))
	{
	    printf("The string S is Empty!\n");/*��S�ǿյ�*/
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
* ��������StrIncert
* ��  �ܣ������в���һ���ִ�
* ��  �Σ�string S��Ŀ�괮
          int pos�� Ҫ�����λ��
		  string T��Ҫ������ַ���
* ����ֵ��OK or ERROR
**************************************************
*/
Status StrIncert(string S,int pos,string T)
{
    int i;
	if(pos >= 1 && pos <= StrLength(S)+1)
	{
		/*��ȫ����*/
		if(StrLength(S) + StrLength(T) <= MAXSIZE)
		{
	        for(i = StrLength(S)+StrLength(T);i >= pos+StrLength(T);i--)
	        {
	            S[i] = S[i - StrLength(T)];/*�����λ����*/
	        }
	        for(i = pos;i < pos+StrLength(T);i++)
	        {
	            S[i] = T[i-pos+1];/*��ֵ����*/
	        }
		    S[0] = S[0]+StrLength(T);
	        return OK;		
		}
		/*����ȫ����*/
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
* ��������Replace
* ��  �ܣ����S�д��ں�T��ȵ��Ӵ�����ô��ȫ���滻ΪV
* ��  �Σ�string S:Ŀ�괮
          string T��Ҫ���ҵĴ�
		  string V��Ҫ�滻�Ĵ�
* ����ֵ��OK or ERROR
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
			i = i + StrLength(V) + 2;/*+2���ܵ����µ�һλ*/
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