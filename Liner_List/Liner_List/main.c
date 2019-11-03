#include "Sqlist.h"
#include "stdio.h"

Sqlist L,L2;

#if  0
int main(void)
{
	int i;
	int value;
	L.length = 5;
	L2.length = 3;
	for(i = 0;i < L.length;i ++)
	{
		L.data[i] = i;
	}
	Incert_Elem(&L,2,8);
	Delet_Elem(&L,2,&value);
	ClearList(&L);
	printf("The delet value is:%d\n",value);
	printf("The length is:%d\n",L.length);
	printf("The data is:\n");
	for(i = 0;i < L.length;i ++)
	{
		printf("%d\n",L.data[i]);  
	}
	
}

#else

int main(void)
{
	int i;
	L.length = 3;
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;

	L2.length = 3;
	L2.data[0] = 6;
	L2.data[1] = 7;
	L2.data[2] = 4;
	for(i = 0;i < L2.length;i++)
	{
		if(LocateElem(L,L2.data[i]))
		{
			Incert_Elem(&L,L.length+1,L2.data[i]);
		}
	}
	printf("The data is:\n");
	for(i = 0;i < L.length;i++)
	{
		printf("%d\n",L.data[i]);
	}

}


#endif