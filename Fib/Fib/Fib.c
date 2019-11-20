#include "Fib.h"

/*
**********************************************************
* 函数名：Fib
* 功  能：采用递归计算菲波那切数列的值
* 形  参：int value：要计算的第几号序列值
* 返回值：Element要返回的计算结果值
*********************************************************
*/
Element Fib(int value)
{
    if(value < 2)
	{
	    return value == 0 ? 0 : 1;
	} 
	else
		return value = Fib(value - 1) + Fib(value - 2);  
}
