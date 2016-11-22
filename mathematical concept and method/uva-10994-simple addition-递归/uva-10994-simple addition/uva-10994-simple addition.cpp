// uva-10994-simple addition.cpp : 定义控制台应用程序的入口点。
//给出l和r，求∑(l≤i≤r)F(i)

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
long long int P, Q, res;
long long int F(long long int n)
{
    if(n == 0)
        return 0;
    if(n % 10)
        return n % 10;
    return F(n / 10);
}
void dfs(long long int x, long long int y)
{
    long long int i;
    if(y - x < 10)//差距在10内 直接计算
    {
        for(i = x; i <= y; i ++)
            res += F(i);
        return;
    }
	//x增 y减到10的倍数
    for(; x % 10; x ++)
        res += F(x);
    for(; y % 10; y --)
        res += F(y);
	//x y此时为10倍数 
	//x:y中 个位数为1:9的数有(y-x)/10组
	//比如x=20 y=40则21,22,23...39一共是2组1:9
	//而21...29计算一组F为1+2+...+9=45 因此为45*(y-x)/10为总和
    res += 45 * ((y - x) / 10);
    dfs(x / 10, y / 10);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%lld%lld", &P, &Q))
	{
		if(P==-1&&Q==-1)
			break;
		res = 0;
		dfs(P, Q);
		printf("%lld\n", res);
	}
	return 0;
}

