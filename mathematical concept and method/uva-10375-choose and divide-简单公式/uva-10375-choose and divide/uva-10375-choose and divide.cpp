// uva-10375-choose and divide.cpp : 定义控制台应用程序的入口点。
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
int P, Q, R, S;
void solve()
{
    int i, j, k;
    double ans = 1.0;
    if(P - Q < Q)
        Q = P - Q;
    if(R - S < S)
        S = R - S;
    for(i = 1; i <= S || i <= Q; i ++)
    {
        if(i <= Q)
            ans = ans * (P - Q + i) / i;
        if(i <= S)
            ans = ans / (R - S + i) * i;
    }
    printf("%.5lf\n", ans);
}
int main()
{
    while(scanf("%d%d%d%d", &P, &Q, &R, &S) == 4)
        solve();
    return 0;
}

