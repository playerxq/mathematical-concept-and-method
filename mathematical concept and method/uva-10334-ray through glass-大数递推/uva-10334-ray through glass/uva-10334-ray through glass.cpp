// uva-10334-ray through glass.cpp : 定义控制台应用程序的入口点。
//

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
int n;
int f[1010][1010];
int l[1010];
void add_f(int x)//f[i] = f[i-1]+f[i-2]
{
	int i = 0;
	int c = 0;
	int cur = 0;
	for(int j = 0;j<l[x-1]||c;j++)
	{
		cur= (f[x-1][j]+f[x-2][j]+c);
		c = cur/10;
		f[x][i++] = cur%10;
	}
	l[x] = i;
	return;
}
void print(int k)
{
	int i;
	for(i = l[k]-1;i>=0;i--)
		if(f[k][i])
			break;
	for(;i>=0;i--)
	{
		printf("%d",f[k][i]);
	}
	printf("\n");
}
void init()
{
	f[0][0] = 1;
	f[1][0] = 2;
	l[0] = l[1] = 1;
	for(int i = 2;i<1010;i++)
	{
		add_f(i);
	}
	return;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n)!=EOF)
	{
		print(n);
	}
	return 0;
}

