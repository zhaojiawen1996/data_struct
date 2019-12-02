#include "KMP.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/*
*********************************************
* ��������get_next
* ��  �ܣ�����next����
* ��  �Σ�string T��ģʽ��
          int *next��Ҫ���ɵ�next����
* ����ֵ����
*********************************************
*/
void get_next(string T,int *next)
{
    int i = 1;
	int j = 0;
	next[1] = 0;
	while(i < T[0])/*T[0]�Ǵ�T�ĳ���*/
	{
	    if(j == 0 || T[i] == T[j])
		{
		    i++;/*��S������*/
			j++;/*ģʽ��������*/
			next[i] = j; 
		}
		else
		{
			j = next[j];/*jֵ���л���*/
		}
	}
}

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
******************************************************
* ��������Index_KMP
* ��  �ܣ�����KMP�㷨��������S��pos��λ��֮����T��ƥ���λ�á�
* ��  �Σ�string S��Ҫƥ�������
          string T: ��ƥ���ģʽ��
		  int pos ��λ��
* ����ֵ�������ж�Ӧ��λ��
******************************************************
*/
int Index_KMP(string S,string T,int pos)
{
    int i = pos;/*�������±꣬��Ϊ�Ǵ�posλ�ÿ�ʼѰ�ң���˽�posֵ��ֵ��i*/
	int j = 1;/*ģʽ�����±�*/
	int next[10];/*�˴�next���±����ģʽ���ĳ��Ƚ����趨������Ƕ��ʽϵͳ���������ù��������ջ���*/
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
* ��������get_nextval
* ��  �ܣ���ȡģʽ����next���飨�Ľ�������飩
* ��  �Σ�string T�� ģʽ��
          int *next��Ҫ�����next����
* ����ֵ��void
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
		    j = next[j];/*jֵ���л���*/
		}
	}
}