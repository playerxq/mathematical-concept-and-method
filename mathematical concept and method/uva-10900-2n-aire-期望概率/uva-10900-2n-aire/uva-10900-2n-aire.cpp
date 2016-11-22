// uva-10900-2n-aire.cpp : 定义控制台应用程序的入口点。
//
/*
玩家初始的金额为1，给出n，表示有n道题目，t表示说答对一道题目的概率在t到1之间
每次面对一道题，可以选择结束游戏，获得当前奖金；回答下一道问题，答对的概率p在t到1之间
答对的话奖金翻倍，答错的话结束游戏，没有奖金，求玩家赢的奖金的期望值的最大值。
*/
/*
ans为当前获得的最优奖金期望，初始化为2^(n)，所求为i=0时的ans
设已经答对了i个题目，奖金已经得到2^i，第i+1题答对概率为p
即i+1题时有p概率获得ans奖金，1-p概率获得奖金为0，因此期望为p*ans，如果p*ans>2^i，即大于当前i个题目的奖金，则选择答题。
计算2^i/ans作为p的临界值。如果t大于此值，则p必然大于临界值，必然选择答题。否则将此临界值作为t:1的临界点分情况。
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
const int N = 35;
double v[N];
double t;
int n;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	v[0] = 1;
	for(int i = 1;i<=30;i++)
		v[i] = v[i-1]*2;//2^i
	while(scanf("%d%lf",&n,&t))
	{
		if(n+t==0)
			break;
		if(fabs(1-t)<1e-9)
			printf("%.3lf\n",v[n]);
		else
		{
			double ans = v[n];//ans为当前获得的最优奖金期望
			for(int i = n-1;i>=0;i--)//查看第i+1个题目是否答
			{
				double f = v[i]/ans;
				if(f<=t)//任何p都可以使得p*ans>2^i  故答第i+1题 概率p为t:1均值
				{
					ans = (1+t)/2*ans;//答第i+1题，当前获得的奖金由i+1题的概率p修正
				}
				else//p落在t:f处不答  取第i次最优的2^i  落在f:1答i+1题 取p=(1+f)/2均值下最优期望 此时获得的奖金需要被p修正
				{
					ans = ((f - t) / (1 - t)) * v[i] + ((1 - f) / (1 - t)) * (1 + f) / 2*ans;
				}
			}
			printf("%.3lf\n",ans);
		}
	}
	return 0;
}

