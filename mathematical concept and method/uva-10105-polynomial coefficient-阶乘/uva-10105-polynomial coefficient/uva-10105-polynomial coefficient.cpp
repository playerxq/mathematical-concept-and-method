// uva-10105-polynomial coefficient.cpp : 定义控制台应用程序的入口点。
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
int a[15];
int get_jiecheng(int n)
{
	int sum = 1;
	for(int i = 1;i<=n;i++)
		sum*=i;
	return sum;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		memset(a,0,sizeof(a));
		for(int i = 1;i<=k;i++)
			scanf("%d",&a[i]);
		int sum = 1;
		for(int i = 1;i<=k;i++)
		{
			sum*=get_jiecheng(a[i]);
		}
		int sum1 = get_jiecheng(n);
		printf("%d\n",sum1/sum);
	}
	return 0;
}

