// uva-10491-cow and car.cpp : �������̨Ӧ�ó������ڵ㡣
//�����߻ῴ�����ȹر��˵��ţ�����һ�ȵĺ�����һ��������
//ѡ�к����г��������ſ�Ӯ�ø����������������ź����������һֻɽ��
//��������ѡ����һ���ţ���δȥ��������ʱ�򣬽�Ŀ�����˿���ʣ�������ŵ�����һ�ȣ�¶������һֻɽ��
//�����������ʲ�����Ҫ��Ҫ����һ����Ȼ���ϵ��š������ǣ�����һ���Ż�����Ӳ�����Ӯ�������ĸ��ʣ�
//���ڣ�����NCOWSֻţ��NCARS������NSHOW�ȿ������ţ� NSHOW < NCOWS��

//�ʣ����ź�Ӯ�ó��ĸ����ǣ�

//P(Ӯ������)

//=P(�ʼѡ�������ź���ɽ��)*P(���ʼѡ�������ź���ɽ��������ʣ�������ź��ǳ�)
//+P(�ʼѡ�������ź��ǳ�)*P(���ʼѡ�������ź��ǳ��������ʣ�������ź��ǳ�)
//��A={�ʼѡ�������ź���ɽ��}��B={�ڶ���ѡ���ź��ǳ�}

//����ȫ���ʹ�ʽ�ã�
//p(B) = p(A)P(B/A)+p(!A)p(B/!A)
//������p(A)=ncow/(ncow+ncar)
//p(B/A)=ncar/(ncow-1-nshow+ncar)  ȥ��չʾ������cow
//p(B/!A) = ncar-1/(ncar-1-nshow+ncow)  ȥ��չʾ�������Ǹ�car
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
using namespace std;

int main(void)
{
	int cow, car, show, temp;
	while (~scanf("%d%d%d", &cow, &car, &show))
	{
		temp = cow + car - 1;
		printf("%.5f\n", (double)temp * car / ((temp + 1) * (temp - show)));
	}
	return 0;
}

