// uva-10169-urn ball probability.cpp : 定义控制台应用程序的入口点。
//记f[i]表示前i次操作中至少有一次操作取出的两个球都是红球的概率, p[i]是第i次取出的两个球都是红球的概率。
//则可推出一个递归关系： f[i+1] = f[i] + (1-f[i])*p[i+1] 
//f[1] = 1/2;
//f[2] = f[1] + (1-f[1])*(1/2)*(1/3);
//f[3] = f[2] + (1-f[2])*(1/3)*(1/4);
//ans = p[1]*p[2]*p[3]*p[4].......p[n]
//ans = 10^i  i = d+a  d为整数
//ans = 10^d*10^a  -1<a<0 则0.1<10^a<1 则小数点后连续的0只取决于10^d d的大小
//log(ans) = log(p[1])+log(p[2])+log(p[3])+log(p[4])+........+log(p[n]);
//log(ans)的整数部分。

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
#define N 1000005
int n;
double f[N];
double p[N];
double q[N];
void init()
{
	f[0] = 0.0;
	p[0] = 0.0;
	q[0] = 0.0;
	for(int i = 1;i<N;i++)
	{
		p[i] = (double)(1.0*i*(i+1));
		q[i] = q[i-1]+log10(p[i]);
	}
	for(int i = 1;i<N;i++)
	{
		f[i] = f[i-1]+(1-f[i-1])/p[i];
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n)!=EOF)
	{
		printf("%.6lf %d\n",f[n],(int)q[n]); 
	}
	return 0;
}

