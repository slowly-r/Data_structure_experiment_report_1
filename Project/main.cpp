#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>

using namespace std;		//����std�����ռ��е����г�Ա����ǰ�������ռ���

#define SElemType int		//�궨������ķ�������Ϊint
#define Status int

#define MAXSIZE 100			//˳��ջ�洢�ռ�ĳ�ʼ������
typedef struct
{
	SElemType* base;		//ջ��ָ��
	SElemType* top;			//ջ��ָ��
	int Stacksize;			//ջ���õ��������
}SqStack;

SqStack S;					//����һ��ջ
int e;

Status InitStack(SqStack& S)			//����һ����ջS
{
	S.base = new SElemType[MAXSIZE];
	if (!S.base)	exit(OVERFLOW);
	S.top = S.base;
	S.Stacksize = MAXSIZE;
	return 1;
}

Status Push(SqStack& S, SElemType e)	//����Ԫ��eΪ�µ�ջ��Ԫ��
{
	if (S.top - S.base == S.Stacksize)	return 0;
	*S.top++ = e;
	return 1;
}

Status Pop(SqStack& S, SElemType& e)	//ɾ��S��ջ��Ԫ�أ���e������ֵ
{
	if (S.top == S.base)	return 0;
	e = *--S.top;
	return	1;
}

SElemType GetTop(SqStack S)				//����S��ջ��Ԫ�أ����޸�ջ��ָ��
{
	if (S.top != S.base)
		return *(S.top - 1);
	else
		return 0;
}

SElemType StackEmpty(SqStack S)			//�ж��Ƿ�Ϊ��ջ
{
	if (S.base == S.top)
		return 1;
	else
		return 0;
}


void conversion(int N)		//ת������������Ĳ���ΪҪת����ʮ������
{
	InitStack(S);
	while (N)
	{
		Push(S, N % 8);		//���ν���λѹ��ջ��
		N = N / 8;
	}
	cout << "ʮ����ת�˽��ƣ�";
	while (!StackEmpty(S))
	{
		Pop(S, e);			//����ȡ��
		cout << e;
	}
	cout << endl;
}

int main(void)
{
	int in_num;
	cout << "����ʮ������ֵ��";
	cin >> in_num;
	conversion(in_num);
}


