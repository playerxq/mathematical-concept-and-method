// uva-10910-mark distribution.cpp : 定义控制台应用程序的入口点。
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
int N, T, P;
void solve()
{
    int i;
    long long int m, n, res;
    n = T - P * N;
    if(n < 0)
        printf("0\n");
    else
    {
        m = T - P * N + N - 1;
        if(m - n < n)
            n = m - n;
        res = 1;
        for(i = 1; i <= n; i ++)
            res = res * (m - i + 1) / i;
        printf("%lld\n", res);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d%d", &N, &T, &P);
        solve();
    }
    return 0;
}

