// uva-10940-throw card away.cpp : 定义控制台应用程序的入口点。
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
long long f[500001];
void init()
{
	f[1] = 1;
	f[2] = 2;
	for(int i = 3;i<500001;i++)
	{
		if(i%2==0)
			f[i] = 2*f[i/2];
		else
			f[i] = 2*f[i/2+1]-2;
	}
}
int n;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		printf("%lld\n",f[n]);
	}
	return 0;
}

