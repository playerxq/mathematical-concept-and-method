// uva-10759-dice throw.cpp : �������̨Ӧ�ó������ڵ㡣
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
long long d[30][155];//i��ɫ�ӵõ�j��
int n,x;
long long m,z;
long long gcd(long long a, long long b)
{
	return b==0?a:gcd(b,a%b);
}
long long my_pow(int a, int k)  
{  
    long long ans = 1;  
    for(int i = 0; i < k; i++) ans*=a;  
    return ans;  
} 
long long dp()
{
	memset(d,0,sizeof(d));
	d[0][0] = 1;
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=x;j++)
		{
			for(int k = 1;k<=6;k++)
			{
				if(j>=k)
					d[i][j]+=d[i-1][j-k];
			}
		}
	}
	z = m;
	for(int i = 1;i<x;i++)
		z-=d[n][i];
	return z;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&x))
	{
		if(n+x==0)
			break;
		m = my_pow(6,n);
		z = dp();
		if(z==0)
			printf("0\n");
		else if(z==m)
			printf("1\n");
		else
		{
			long long g = gcd(m,z);
			printf("%lld/%lld\n",z/g,m/g);
		}
	}
	return 0;
}

