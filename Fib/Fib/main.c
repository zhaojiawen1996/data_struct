#include "stdio.h"
#include "stdlib.h"
#include "Fib.h"

#if 0
int main(void)
{
    int i;
	printf("The result of Fib is:\n");
	for(i = 0;i < 40;i ++)
	{
		printf("%d\n",Fib(i));
	}
}

#else 
int main(void)
{
    int i;
	int a[40];
	a[0] = 1;
	a[1] = 1;
	printf("The result of Fib is:\n");
	printf("%d\n",a[0]);
	printf("%d\n",a[1]);
	for(i = 2;i < 40;i++) 
	{
	    a[i] = a[i-1] + a[i - 2];
		printf("%d\n",a[i]);
	}
}

#endif 