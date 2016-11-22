// uva-10128-queue.cpp : 定义控制台应用程序的入口点。
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
#define MAXD 20
int N, P, Q;
long long int f[MAXD][MAXD][MAXD];//f[i][j][k]i个人 前看j个 后看k个
//最小身高人进入时有i-1个人 进入后状态f[i][j][k]
//进入对首  增加一个前看人数 即原来的f[i-1][j-1][k]被加入
//队尾 增加后看人数 f[i-1][j][k-1]
//中间  i-2个位置  都会被挡住 (i-2)*f[i-1][j][k]
void prepare()
{
    int i, j, k;
    memset(f, 0, sizeof(f));
    f[1][1][1] = 1;
    for(i = 2; i <= 13; i ++)
        for(j = 1; j <= i; j ++)
            for(k = 1; k <= i; k ++)
                f[i][j][k] = f[i - 1][j - 1][k] + f[i - 1][j][k - 1] + (i - 2) * f[i - 1][j][k];
}
int main()
{
    int t;
    prepare();
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d%d", &N, &P, &Q);
        printf("%lld\n", f[N][P][Q]);
    }
    return 0;
}

