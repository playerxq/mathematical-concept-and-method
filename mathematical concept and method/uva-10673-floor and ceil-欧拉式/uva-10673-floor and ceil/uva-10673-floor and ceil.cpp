// uva-10673-floor and ceil.cpp : 定义控制台应用程序的入口点。
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
int x,k;
int p,q;
void gcd(int a, int b, int& d,int& x, int& y)
{
	if(!b)
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		gcd(b,a%b,d,y,x);
		y -=x*(a/b);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&x,&k);
		if(x%k==0)
		{
			if(k%2==0)
			{
				p = k/2;
				q = p;
			}
			else
			{
				p = k/2;
				q = k-p;
			}
		}
		else
		{
			int u = x/k;
			int v = u+1;
			int d = 0;
			int x1 = 0;
			int y1 = 0;
			gcd(u,v,d,x1,y1);
			p = x1*x;
			q = y1*x;
		}
		printf("%d %d\n",p,q);
	}
	return 0;
}

