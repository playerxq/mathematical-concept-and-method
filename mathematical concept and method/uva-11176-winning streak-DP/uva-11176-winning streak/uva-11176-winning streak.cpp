// uva-11176-winning streak.cpp : 定义控制台应用程序的入口点。
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
//f[i][j]到i为止 连续w不超过j的概率 则求和j=0:n (f[n][j]-f[n][j-1])*j即可
double f[501][501];
double pi[501];
int n;
double p;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%lf",&n,&p))
	{
		if(n==0)
			break;
		pi[0] = 1;
		for(int i = 1;i<=n;i++)
			pi[i] = pi[i-1]*p;//pi[i]=p^i
		for(int i = 0;i<=n;i++)
			f[0][i] = 1;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 0;j<=n;j++)
			{
				f[i][j] = f[i-1][j];
				if(i==j+1)//前j=i-1个全是w  则第i个不能也是w
					f[i][j]-=pi[i];//全为w  概率p^i
				else if(i>j+1)//前i-j:i-1共j个是w，第i-j-1是L，且第i个是w情况去除
				{
					f[i][j]-=f[i-j-2][j]*(1-p)*pi[j+1];
				}
			}
		}
		double res = 0;
		for(int i = 1;i<=n;i++)
		{
			res+=i*(f[n][i]-f[n][i-1]);
		}
		printf("%.6lf\n",res);
	}
	return 0;
}

