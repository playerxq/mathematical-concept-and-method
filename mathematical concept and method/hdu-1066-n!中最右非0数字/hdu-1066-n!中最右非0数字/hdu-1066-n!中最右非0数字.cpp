// hdu-1066-n!�����ҷ�0����.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
char n[1005];
int head[2] = {6,4};
int a[10] = {1,1,2,6,4,6,6,2,6,4};
int solve(char* n)
{
	int l = strlen(n);
	int m = n[l-1]-'0';
	int tail,A;
	if(l>1)
		A = head[(n[l-2]-'0') & 1];
	if(m<5)
	{
		tail = a[m];
	}
	else
	{
		tail = (a[m]*( (((n[l-2]-'0')&1 != 0)&&(l>1)) ? 7:2)) % 10;//���һ���� ��4��β��������2 ��4��β����һλΪż ��2Ӧ��2��β ���� ��7��β
	}
	if(l==1)
	{
		return tail;
	}
	else
	{
		char n1[1005];
		register int i;
		int k = (n[0] > '4' ? 1:0);
		n1[0] = '1';
		for(i = k;i<=l-2+k;i++)//ȡ�����5���� ��26ȡ25/5=5 5*5 = 5*k = 10*2+6
			n1[i] = (n[i-k]-'0')*2%10 + (n[i+1-k] > '4' ? 1:0) + '0';//5k = 10a+bʱ k = 2a+(b>4?1:0)
		n1[i]='\0';
		return (A*tail*solve(n1))%10;
	}
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	while(scanf("%s",n)!=EOF)
	{
		cout<<solve(n)<<endl;
	}
}

