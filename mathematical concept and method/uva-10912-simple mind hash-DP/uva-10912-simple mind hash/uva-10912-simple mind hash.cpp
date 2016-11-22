// uva-10912-simple mind hash.cpp : 定义控制台应用程序的入口点。
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
int l,s;
int f[27][27][400];//首字母k 长度i  和为j
int vis[27][27][400];
int dfs(int k,int i, int j)
{
	if(vis[k][i][j])
		return f[k][i][j];
	vis[k][i][j] = 1;
	if(i==0&&j==0)
		return f[k][i][j] = 1;
	if(i==0&&j!=0)
		return f[k][i][j] = 0;
	if(j<k+1)
		return f[k][i][j] = 0;
	if(k+1>26-i+1)
		return f[k][i][j] = 0;
	for(int p = k+1;p<=min(j-i+1,26-i+1);p++)
	{
		f[k][i][j] += dfs(p,i-1,j-p);
	}
	return f[k][i][j];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 1;
	while(scanf("%d%d",&l,&s))
	{
		if(l+s==0)
			break;
		memset(f,0,sizeof(f));
		memset(vis,0,sizeof(vis));
		int ans = 0;
		for(int i = 1;i<=min(s-l+1,26-l+1);i++)
			ans+=dfs(i,l-1,s-i);
		printf("Case %d: %d\n",ncase++,ans);
	}
	return 0;
}

