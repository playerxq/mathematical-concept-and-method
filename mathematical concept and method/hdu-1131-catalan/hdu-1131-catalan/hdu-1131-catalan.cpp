// hdu-1131-catalan.cpp : 定义控制台应用程序的入口点。
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
const int max_len = 10005;
const int maxx = 105;
int caltan[maxx][max_len];
void mul(int* a, int b, int& len)
{
	int c = 0;
	for(int i = 0;i<len;i++)
	{
		int temp = a[i]*b+c;
		a[i] = temp%10;
		c = temp/10;
	}
	while(c)
	{
		a[len++] = c%10;
		c/=10;
	}
}
void div(int* a, int b,int& len)
{
	int c = 0;
	for(int i = len-1;i>=0;i--)
	{
		int temp = (c*10+a[i]);
		a[i] = temp/b;
		c = temp%b;
	}
	while(a[len-1]==0)
		len--;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int len[max_len];
	memset(caltan,0,sizeof(caltan));
	memset(len,0,sizeof(len));
	caltan[0][0]=1;len[0]=1;
	for(int i = 1;i<maxx;i++)
	{
		memcpy(caltan[i],caltan[i-1],sizeof(caltan[i-1]));
		len[i]=len[i-1];
		mul(caltan[i],4*i-2,len[i]);
		div(caltan[i],i+1,len[i]);
	}
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)
			break;
		for(int i = 1;i<=n;i++)
		{
			mul(caltan[n],i,len[n]);
		}
		for(int i = len[n]-1;i>=0;i--)
		{
			printf("%d",caltan[n][i]);
		}
		printf("\n");
	}
}

