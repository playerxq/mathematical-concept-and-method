// uva-106-femats and pythagoras.cpp : 定义控制台应用程序的入口点。
//
/*
本题的要求是当 x，y，z ∈ N，给定一个数 n，找出所有的 x，y，z ≤ n，使得 x² + y² = z² 成立。  
 
 x = a² - b²， y = 2 * a * b， z = a² + b²，(a 与 b 互质，a > b，且一奇一偶)。  
  
 题目要求统计 (x，y，z) 三元组的数量时只统计 x，y 和 z 两两互质的的情况，这个问题用上面的  
 算法就可以解决了。但对于统计 p 的数量，题目并不限定三元组是两两互质的。上式不能生成所有的勾股数。  
 但所有非两两互质的 x0，y0，z0 都可由一组互质的 x，y，z 乘以系数得到。
*/
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
#define M 1000010  
bool vis[M];  
int gcd(int x, int y)  
{  
    if(y==0) return x;  
    return gcd(y,x%y);  
}
int n;
int ans1,ans2;
int x,y,z;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		ans1 = ans2 = 0;
		memset(vis,0,sizeof(vis));
		int len = (int)sqrt((double)n+0.5);
		for(int a = 1;a<=len;a++)
		{
			for(int b = a+1;b<=len;b+=2)
			{
				if(gcd(a,b)!=1)
					continue;
				z = a*a+b*b;
				if(z>n)
					break;
				x = b*b-a*a;
				y = 2*a*b;
				ans1++;
				for(int i = 1;i*z<=n;i++)
				{
					vis[x*i] = vis[y*i] = vis[z*i] = 1;
				}
			}
		}
		for(int i = 1; i <= n; i++) if(vis[i]==0)  
			ans2++;  
        printf("%d %d\n",ans1,ans2);
	}
	return 0;
}

