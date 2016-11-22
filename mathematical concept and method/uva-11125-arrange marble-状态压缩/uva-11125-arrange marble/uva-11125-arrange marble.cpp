// uva-11125-arrange marble.cpp : 定义控制台应用程序的入口点。
//给定n种颜色的球，然后每种有一定个数，求这些球摆放成一圈，同种球连续不超过3个且相邻的球群的个数不相同的方案数。

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
#define MAXD 1100000
int f[MAXD], a[5], b[5];
//f[state]//state低4位为4进制数 分别为pc pn fc fn即之前的石头的颜色 数量以及首尾石头的颜色 数量 高4位为8进制 当前剩余石头的数量
int dp(int state)
{
	int i, j, k, t, st = state, ans = 0, fc, fn, pc, pn;
	if(f[st]!=-1)
		return f[st];
	fc = st % 4, st /= 4;
    fn = st % 4, st /= 4;
    pc = st % 4, st /= 4;
    pn = st % 4, st /= 4;
	k = 0;//剩余石头数目
	for(i = 0;i<4;i++)
	{
		b[i] = st%8;
		st/=8;
		k+=b[i];
	}
	if(k == 0)
    {
        if(pc == fc && pn == fn)//到达尾部
            return f[state] = 1;
        else
            return f[state] = 0;
    }
	for(i = 0;i<4;i++)
	{
		if(i==pc)//不能等于之前的颜色
			continue;
		for(j = 1;j<=min(3,b[i]);j++)
		{
			if(j==pn)//数目不能等于之前群的数目
				continue;
			b[i]-=j;
			for(k = 3,t = 0;k>=0;k--)
			{
				t = t*8+b[k];
			}
			//pn = j pc = i
			t = (((t*4+j)*4+i)*4+fn)*4+fc;
			ans += dp(t);
			b[i]+=j;
		}
	}
	return f[state] = ans;
}
void solve()
{
    int i, j, k, n, res, t;
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    k = 0;
    for(i = 0; i < n; i ++)//n种石头 以及每种个数 n<=4 a[i]<=8
    {
        scanf("%d", &a[i]);
        k += a[i];
    }
    if(!k)
    {
        printf("1\n");
        return ;
    }
	//设置初始状态
    for(i = 3, k = 0; i >= 0; i --)
        k = k * 8 + a[i];
    res = 0;
	//初始让fc fn枚举  且pc pn等于fc fn 则只需每次枚举的数目与颜色不等于pc pn即可
    for(i = 0; i < n; i ++)
        for(j = 1; j <= 3 && j <= a[i]; j ++)//每组不超过3个
        {//pc = fc = i  pn = fn = j
            t = (((k * 4 + j) * 4 + i) * 4 + j) * 4 + i;
            res += dp(t);
        }
    printf("%d\n", res);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
    memset(f, -1, sizeof(f));
    scanf("%d", &t);
    while(t --)
        solve();
    return 0;
}

