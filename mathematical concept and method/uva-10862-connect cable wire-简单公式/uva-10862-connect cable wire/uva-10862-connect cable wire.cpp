// uva-10862-connect cable wire.cpp : 定义控制台应用程序的入口点。
//f[n] = (3)*f[n-1]-f[n-2]

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
int f[2001][1001];
int l[2001];
void mul(int x,int k)//f[x] = f[x-1]*k
{
	int c = 0;
	int cur = 0;
	int j = 0;
	for(int i = 0;i<l[x-1]||c;i++)
	{
		cur = k*f[x-1][i]+c;
		f[x][j++] = cur%10;
		c = cur/10;
	}
	l[x] = j;
	return;
}
void del(int x, int y)//f[x] = f[x]-f[y]
{
	for(int i = 0;i<l[y];i++)
	{
		if(f[x][i]>=f[y][i])
		{
			f[x][i]-=f[y][i];
		}
		else
		{
			f[x][i]+=10;
			f[x][i+1]-=1;
			f[x][i]-=f[y][i];
		}
	}
	for(int i = l[x]-1;i>=0;i--)
		if(f[x][i])
		{
			l[x] = i+1;
			break;
		}
	return;
}
void init()
{
	f[0][0] = 0;
	f[1][0] = 1;
	f[2][0] = 3;
	l[0] = 1;
	l[1] = 1;
	l[2] = 1;
	for(int i = 3;i<2001;i++)
	{
		mul(i,3);
		del(i,i-2);
	}
	return;
}
int n;
void print(int k)
{
	for(int i = l[k]-1;i>=0;i--)
		printf("%d",f[k][i]);
	printf("\n");
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		print(n);
	}
	return 0;
}

