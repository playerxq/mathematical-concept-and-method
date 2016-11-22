// uva-10417-gift exchange.cpp : �������̨Ӧ�ó������ڵ㡣
//AiΪ��1���˴������ǵ�i��gift��
//�¼�BΪ�����˵�gift��һ����ֳ���Ŀ�и�����ÿ����ٸ�����״̬��
//��ôP(Ai|B)�Ͷ�Ӧ��ʾ�ڵ�ǰ����״̬�µ�1���˴������ǵ�i��gift�ĸ��ʣ�
//Ȼ����Ե�i��gift�ĸ�������
//�ӵ�һ���˿�ʼ��ÿ���û�ȥ�Լ�������ÿ�Ϊֹ��
//��f[i][j]��ʾ�ܴﵽ��i������������״̬jʱ��������ĸ��ʣ�j��13���Ƽ��ɣ�
//f[i][j]=SUM{g[i][ai]*f[i+1][j-ai]}������g[i][ai]Ϊ��i���˴�������ai���gift�ĸ��ʣ�j-ai��ʾ��i��������ai��ʣ���gift��״̬
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
double f[MAXN][MAXD],g[MAXN][MAXB];//f[i][j]��i���˿�ʼȡ����ʱ��Ե�����״̬j
int vis[MAXN][MAXD],a[MAXB],b[MAXB],gift[MAXB];
int n;
double dfs(int i, int j)
{
	if(vis[i][j])
		return f[i][j];
	int next = j;
	double ans = 0;
	for(int k = 5;k>=1;k--)//�õ���ǰ����״̬
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
				scanf("%lf", &g[i][j]);//��i�����ڵ�j������ĸ���
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
				for(j = 1,k = 0; j <= 5; j ++)//ȥ��ĳ��������״̬
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

