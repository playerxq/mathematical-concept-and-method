// uva-10994-simple addition.cpp : �������̨Ӧ�ó������ڵ㡣
//����l��r�����(l��i��r)F(i)

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
    if(y - x < 10)//�����10�� ֱ�Ӽ���
    {
        for(i = x; i <= y; i ++)
            res += F(i);
        return;
    }
	//x�� y����10�ı���
    for(; x % 10; x ++)
        res += F(x);
    for(; y % 10; y --)
        res += F(y);
	//x y��ʱΪ10���� 
	//x:y�� ��λ��Ϊ1:9������(y-x)/10��
	//����x=20 y=40��21,22,23...39һ����2��1:9
	//��21...29����һ��FΪ1+2+...+9=45 ���Ϊ45*(y-x)/10Ϊ�ܺ�
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

