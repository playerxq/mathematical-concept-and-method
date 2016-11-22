// uva-11069-graph problem.cpp : 定义控制台应用程序的入口点。
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
int n;
int f[77];
void init()
{
	f[1] = 1;
	f[2] = 2;
	f[3] = 2;
	for(int i = 4;i<77;i++)
	{
		f[i] = f[i-2]+f[i-3];
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",f[n]);
	}
	return 0;
}

