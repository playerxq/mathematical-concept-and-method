// uva-10616-divisible group sum.cpp : 定义控制台应用程序的入口点。
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
#define MAXN 210
#define MAXD 30
#define MAXM 15
//f[i][j][k]表示选到第i个数时一共选了j个数且它们的和模D的值为k，
//f[i][j][k]=f[i-1][j][k]+f[i-1][j-1][x]，(i选or不选) 其中x满足0<=x<D且(x+a[i]%D)%D=k，边界为f[0][0][0]=1。
int N, Q, M, D;
long long int a[MAXN], f[MAXN][MAXM][MAXD];
void init()
{
	int i, j, k, t;
    memset(f, 0, sizeof(0));
    f[0][0][0] = 1;
    for(i = 1; i <= N; i ++)
        for(j = 0; j <= M; j ++)
            for(k = 0; k < D; k ++)
            {
                f[i][j][k] = f[i - 1][j][k];
                if(j)
                {
                    t = (D + k - a[i] % D) % D;//k = (t+a[i]%D)%D 
                    f[i][j][k] += f[i - 1][j - 1][t];
                }
            }
    printf("%lld\n", f[N][M][0]);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 1;
	while(scanf("%d%d",&N,&Q))
	{
		if(N+Q==0)
			break;
		for(int i = 1; i <= N; i ++)
            scanf("%lld", &a[i]);
        printf("SET %d:\n", ncase++);
		for(int i = 1; i <= Q; i ++)
        {
            scanf("%d%d", &D, &M);
            printf("QUERY %d: ", i);
            init();
        }
	}
	return 0;
}

