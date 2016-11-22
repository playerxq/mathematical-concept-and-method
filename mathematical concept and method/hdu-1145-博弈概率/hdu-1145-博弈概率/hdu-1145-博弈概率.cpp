// hdu-1145-博弈概率.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
double ex[35];
double mon[35];
int n = 0;
double bp = 0;
double t = 0;
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	mon[0]=1;
	for(int i = 1;i<=30;i++)
		mon[i] = mon[i-1]*2;
	while(scanf("%d%lf",&n,&t)!=EOF&&(n>0))
	{
		ex[n] = mon[n];
		for(int i = n-1;i>=0;i--)
		{
			bp = mon[i]/ex[i+1];
			if(bp<=t)
			{
				ex[i] = (1+t)/2*ex[i+1];
			}
			else
			{
				ex[i] = (bp-t)/(1-t)*mon[i]+(1-bp)/(1-t)*ex[i+1]*(1+bp)/2;
			}
		}
		printf("%.3lf\n",ex[0]);
	}
}
