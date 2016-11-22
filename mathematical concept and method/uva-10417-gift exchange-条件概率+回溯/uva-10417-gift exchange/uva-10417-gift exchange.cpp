// uva-10417-gift exchange.cpp : 定义控制台应用程序的入口点。
//Ai为第1个人带来的是第i类gift，
//事件B为所有人的gift放一起呈现出题目中给出的每类多少个那种状态。
//那么P(Ai|B)就对应表示在当前这种状态下第1个人带来的是第i类gift的概率，
//然后除以第i类gift的个数即可
//从第一个人开始，每人拿回去自己的礼物，拿空为止。
//设f[i][j]表示能达到第i个人面临礼物状态j时这种情况的概率，j用13进制即可，
//f[i][j]=SUM{g[i][ai]*f[i+1][j-ai]}，其中g[i][ai]为第i个人带来的是ai这个gift的概率，j-ai表示第i个人拿走ai后剩余的gift的状态
//P(AiB)=g[1][ai]*f[2][k-ai]  p(B) = f[1][k]
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
const int MAXN = 13;
const int MAXB = 6;
const int MAXD = 350000;
double f[MAXN][MAXD],g[MAXN][MAXB];//f[i][j]第i个人开始取礼物时面对的礼物状态j
int vis[MAXN][MAXD],a[MAXB],b[MAXB],gift[MAXB];
int n;
double dfs(int i, int j)
{
	if(vis[i][j])
		return f[i][j];
	int next = j;
	double ans = 0;
	for(int k = 5;k>=1;k--)//得到当前礼物状态
	{
		a[k] = next%13;
		next/=13;
	}
	for(int k = 1;k<=5;k++)
	{
		if(a[k])
		{
			--a[k];
			int k1 = 0;
			for(int l = 1; l <= 5; l ++)
                k1 = k1 * 13 + a[l];
			ans+=dfs(i+1,k1)*g[i][k];
			++a[k];
		}
	}
	vis[i][j] = 1;
	return f[i][j] = ans;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i, j, k, box;
		double max, ans, res;
		scanf("%d",&n);
		for(i = 1;i<=5;i++)
			scanf("%d",&gift[i]);
		for(i = 1; i <= n; i ++)
			for(j = 1; j <= 5; j ++)
				scanf("%lf", &g[i][j]);//第i个人于第j类礼物的概率
		for(i = 1, k = 0; i <= 5; i ++)
			k = k * 13 + gift[i];
		memset(vis, 0, sizeof(vis));
		vis[n + 1][0] = 1;
		f[n + 1][0] = 1;
		res = dfs(1, k);
		max = -1;
		for(i = 1; i <= 5; i ++)
			if(gift[i])
			{
				-- gift[i];
				for(j = 1,k = 0; j <= 5; j ++)//去除某个礼物后的状态
					k = k * 13 + gift[j];
				++ gift[i];
				ans = f[2][k] * g[1][i] / gift[i];
				if(ans / res > max + 1e-9)
				{
					max = ans / res;
					box = i;
				}
			}
		printf("%d %.3lf\n", box, max);

	}
	return 0;
}

