// uva-10943-how do you add.cpp : 定义控制台应用程序的入口点。
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
int f[101][101];//
int vis[101][101];
int dfs(int i,int j)
{
	if(vis[i][j])
		return f[i][j];
	vis[i][j] = 1;
	if(j==1)
	{
		f[i][j] = 1;
		return f[i][j];
	}
	if(i==0)
		return f[0][j] = 1;
	for(int k = 0;k<=i;k++)
	{
		f[i][j]+=dfs(i-k,j-1);
		if(f[i][j] >= 1000000) f[i][j] %= 1000000; 
	}
	return f[i][j];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&k))
	{
		if(!n&&!k)
			break;
		memset(vis,0,sizeof(vis));
		memset(f,0,sizeof(f));
		int ans = dfs(n,k);
		printf("%d\n",ans);
	}
	return 0;
}

