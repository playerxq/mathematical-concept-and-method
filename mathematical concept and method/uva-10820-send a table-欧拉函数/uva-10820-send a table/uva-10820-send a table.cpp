// uva-10820-send a table.cpp : 定义控制台应用程序的入口点。
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
#define MAXD 50010
int n, phi[MAXD], a[MAXD];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void get_pi()// 计算欧拉函数phi[i]=1:i-1与i互素元素个数  包含1
{
	memset(phi,0,sizeof(phi));
	phi[1] = 1;
	for(int i = 2;i<=50000;i++)
	{
		if(phi[i]==0)
		{
			for(int j = i;j<=50000;j+=i)
			{
				if(!phi[j])
					phi[j] = j;
				phi[j] = (phi[j]/i)*(i-1);
			}
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	get_pi();
	while(scanf("%d",&n)&&n)
	{
		int sum = 0;
		for(int i = 1;i<=n;i++)
		{
			sum+=phi[i];
		}
		printf("%d\n",2*sum-1);
	}
	return 0;
}

