#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

using namespace std;		//引入std命名空间中的所有成员到当前的命名空间中

#define SElemType int		//宏定义特殊的返回类型为int
#define Status int

#define MAXSIZE 100			//顺序栈存储空间的初始分配量
typedef struct
{
	SElemType* base;		//栈底指针
	SElemType* top;			//栈顶指针
	int Stacksize;			//栈可用的最大容量
}SqStack;

SqStack S;					//定义一个栈
int e;

Status InitStack(SqStack& S)			//构建一个空栈S
{
	S.base = new SElemType[MAXSIZE];
	if (!S.base)	exit(OVERFLOW);
	S.top = S.base;
	S.Stacksize = MAXSIZE;
	return 1;
}

Status Push(SqStack& S, SElemType e)	//插入元素e为新的栈顶元素
{
	if (S.top - S.base == S.Stacksize)	return 0;
	*S.top++ = e;
	return 1;
}

Status Pop(SqStack& S, SElemType& e)	//删除S的栈顶元素，用e返回其值
{
	if (S.top == S.base)	return 0;
	e = *--S.top;
	return	1;
}

SElemType GetTop(SqStack S)				//返回S的栈顶元素，不修改栈顶指针
{
	if (S.top != S.base)
		return *(S.top - 1);
	else
		return 0;
}

SElemType StackEmpty(SqStack S)			//判断是否为空栈
{
	if (S.base == S.top)
		return 1;
	else
		return 0;
}


void conversion(int N)		//转换函数，传入的参数为要转换的十进制数
{
	InitStack(S);
	while (N)
	{
		Push(S, N % 8);		//依次将低位压入栈中
		N = N / 8;
	}
	cout << "十进制转八进制：";
	while (!StackEmpty(S))
	{
		Pop(S, e);			//依次取出
		cout << e;
	}
	cout << endl;
}

int main(void)
{
	int in_num;
	cout << "输入十进制数值：";
	cin >> in_num;
	conversion(in_num);
}


