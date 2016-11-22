// uva-11181-probability given.cpp : 定义控制台应用程序的入口点。
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
#define MAXD 25
int N, R;
double ap[MAXD], p[MAXD];
void solve()
{
    int i, j, k;
    double ans, rp = 0;
    for(i = 0; i < N; i ++)
        scanf("%lf", &p[i]);
    if(R == 0)
    {
        for(i = 0; i < N; i ++)
            printf("0.000000\n");
        return ;
    }
    memset(ap, 0, sizeof(ap));
    for(i = 0; i < (1 << N); i ++)//每个状态
    {
        k = 0;
        for(j = 0; j < N; j ++)//当前状态中1的个数  即买的人数
            if((1 << j) & i)
                k ++;
        if(k == R)//r个人买了
        {
            ans = 1;//当前概率
            for(j = 0; j < N; j ++)
            {
                if((1 << j) & i)
                    ans *= p[j];
                else
                    ans *= (1 - p[j]);
            }
            rp += ans;//累加全部状态中恰有R个1时的概率
            for(j = 0; j < N; j ++)//r个人买了同时第j个人买
                if((1 << j) & i)
                    ap[j] += ans;//单独累加第j个位为1时，全部1有R个时的概率
        }
    }
    for(i = 0; i < N; i ++)
        printf("%.6lf\n", ap[i] / rp);
}
int main()
{
    int t = 0;
    for(;;)
    {
        scanf("%d%d", &N, &R);
        if(!N && !R)
            break;
        printf("Case %d:\n", ++ t);
        solve();
    }
    return 0;
}

