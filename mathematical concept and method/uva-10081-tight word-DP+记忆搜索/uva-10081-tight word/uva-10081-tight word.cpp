// uva-10081-tight word.cpp : 定义控制台应用程序的入口点。
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
int n,k;
double f[10][101];//首字母i 总长j
int vis[10][101];
long double dfs(int i, int j)
{
	if(vis[i][j])
		return f[i][j];
	vis[i][j] = 1;
	if(j==1)
	{
		f[i][j] = 1.0/(k+1);
		return f[i][j];
	}
	if(i==0)
	{
		return f[i][j] = 1.0/(k+1)*(dfs(i,j-1)+dfs(i+1,j-1));
	}
	else if(i==k)
	{
		return f[i][j] =1.0/(k+1)*(dfs(i,j-1)+dfs(i-1,j-1));
	}
	else
	{
		return f[i][j] = 1.0/(k+1)*(dfs(i,j-1)+dfs(i+1,j-1)+dfs(i-1,j-1));
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&k,&n)!=EOF)
	{
		if(k<=1)
		{
			printf("100.00000\n");
		}
		else
		{
			double ans = 0;
			memset(vis,0,sizeof(vis));
			for(int i = 0;i<=k;i++)
				ans+=dfs(i,n);
			printf("%.5lf\n",ans*100);
		}
	}
	return 0;
}

