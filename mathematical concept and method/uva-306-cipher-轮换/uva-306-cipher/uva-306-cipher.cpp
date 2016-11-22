// uva-306-cipher.cpp : 定义控制台应用程序的入口点。
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
char msg[310];
char msg1[310];
int a[210];
int vis[210];
int p[210][210];
int b[210];
int n,k,cnt;
void process()
{
	cnt = 1;
	memset(vis,0,sizeof(vis));
	for(int i = 1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			int k = 1;
			p[cnt][k++] = i;
			b[i] = cnt;//i在cnt号群中
			int j = a[i];
			while(j!=i)//得到一组轮换数  保证a[i]=i  i经过p[cnt][0]步可以换为自己
			{
				p[cnt][k++] = j;
				b[j] = cnt;
				vis[j] = 1;
				j = a[j];
			}
			p[cnt][0] = k-1;//置换阶数
			cnt++;
		}
	}
}
void solve()
{
	int len = strlen(msg+1);
	while(len<n)
	{
		++len;
		msg[len] = ' ';
	}
	memset(msg1,0,sizeof(msg1));
	memset(vis,0,sizeof(vis));
	for(int i = 1;i<=len;i++)
	{
		if(vis[i]==0)
		{
			int x = b[i];//所属的群
			for(int j = 1;j<=p[x][0];j++)//对当前群的每个元素
			{
				//经过k步  p[x][j]将轮换到p[x][j+k%p[x][0]]
				vis[p[x][j]] = 1;
				int y = j+k%p[x][0];
				if(y>p[x][0])
					y-=p[x][0];
				msg1[p[x][y]] = msg[p[x][j]];
			}
		}
	}
	for(int i = 1;i<=len;i++)
		printf("%c",msg1[i]);
	printf("\n");
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n))
	{
		if(!n)
			break;
		for(int i = 1;i<=n;i++)
			scanf("%d",&a[i]);
		process();
		while(scanf("%d",&k))
		{
			if(!k)
				break;
			getchar();
			gets(msg+1);
			solve();
		}
		printf("\n");
	}
	return 0;
}

