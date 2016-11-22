// uva-10236-fibonacci prime.cpp : 定义控制台应用程序的入口点。
//除第3,4项外，每个素数作为索引对应的fibonacci数也是素数，即要找到第N个素数作为索引的fibnacii素数
//10^6之内可以产生7万多个素数，因此我们可以先把10^6内的素数筛出来存到数组里
//题目最多取到的素数是第22000个，因此10^6内的素数完全满足 预处理后 p[N-1]就是第N个素数 N<=22000
//再以第N个素数p[N-1]作为索引，求出第p[N-1]个fib数，由于索引为素数的fib数也为素数  即可
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
int N;
long long int fib[60];
int prime[1000010];
int p[1000010];
long double b[200][2];
void init()
{
	int i;
	fib[0] = 0, fib[1] = 1;
    for(i = 2; i < 50; i ++)
        fib[i] = fib[i - 1] + fib[i - 2];//fib[47]是最后一个9位及9位以内的fibonacci素数，47对应的为第14个素数p[14]=p[15-1]
	int k = (int)sqrt((double)1000010+0.5);//计算10^6内所有素数
	memset(prime, -1, sizeof(prime));
	int cnt = 0;
	for(i = 2;i<=k;i++)
	{
		if(prime[i])
		{
			p[cnt++] = i;
			for(int j = i*i;j<1000010;j+=i)
				prime[j] = 0;
		}
	}
	for(;i<1000010;i++)
		if(prime[i])
		{
			p[cnt++] = i;//最多得到7万多素数
		}
	b[0][0] = 0;
	b[0][1] = 1;
	b[1][0] = 1;
	b[1][1] = 1;
}
void pow_m(int n, int c)
{
	if(n==1)
	{
		b[c][0] = 0;
		b[c][1] = 1;
		b[c+1][0] = 1;
		b[c+1][1] = 1;
		return;
	}
	pow_m(n/2,c+2);
	long double A=b[c+2][0] , B=b[c+2][1] , C=b[c+3][0] , D=b[c+3][1];
    b[c][0]=  ( A*A+B*C );
    b[c][1]=  ( A*B+B*D );
    b[c+1][0]=( C*A+D*C );
    b[c+1][1]=( C*B+D*D );
	if(n&1) 
    {
        long double tmp;
        tmp=b[c][0];   b[c][0]=b[c][1];     b[c][1]+=tmp;
        tmp=b[c+1][0]; b[c+1][0]=b[c+1][1]; b[c+1][1]+=tmp;
    }
	while(b[c][0] > 10000)//化为小数防止溢出
        b[c][0] /= 10, b[c][1] /= 10, b[c+1][0] /= 10, b[c+1][1] /= 10;
	return;
}
void solve()
{
    int i, j, n;
    long long int t;
    long double x;
    n = p[N - 1];//计算fib[n]
    pow_m(n, 0);
    x = b[1][0];
    while(x < 100000000)
        x *= 10;
    t = (long long int)x;
    printf("%lld\n", t);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
    while(scanf("%d", &N) == 1)
    {
        if(N <= 2)
            printf("%s\n", N == 1 ? "2" : "3");
        else if(N <= 14)
            printf("%lld\n", fib[p[N - 1]]);//第N个素数为p[N-1]
        else
            solve();
    }
    return 0;
}

