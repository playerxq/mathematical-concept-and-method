// uva-10721-bar code.cpp : 定义控制台应用程序的入口点。
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
int n,k,m;
long long f[60][60][60];
int vis[60][60][60];
long long dfs(int i, int j,int cnt)//一共i个 分j组 首字母1 且已有cnt个连续1
{
	if(vis[i][j][cnt])
		return f[i][j][cnt];
	vis[i][j][cnt] = 1;
	if(i==j)
		return f[i][j][cnt] = 1;
	if(i<j)
		return f[i][j][cnt] = 0;
	if(j<=1)
	{
		if(j==0)
			return f[i][j][cnt] = 0;
		else
		{
			if(m>=i+cnt-1)
				return f[i][j][cnt] = 1;
			else
				return f[i][j][cnt] = 0;
		}
	}
	if(m<i/j)
		return f[i][j][cnt] = 0;
	for(int k = 1;k<=min(i-1,m);k++)
	{
		f[i][j][cnt] += dfs(i-1-k,j-2,1);
	}
	if(cnt<m)
	{
		f[i][j][cnt] += dfs(i-1,j,cnt+1);
	}
	return f[i][j][cnt];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d%d",&n,&k,&m)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		memset(f,0,sizeof(f));
		long long ans = dfs(n,k,1);
		printf("%lld\n",ans);
	}
	return 0;
}

