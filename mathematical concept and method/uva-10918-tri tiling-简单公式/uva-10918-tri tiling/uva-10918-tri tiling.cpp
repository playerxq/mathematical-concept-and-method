// uva-10918-tri tiling.cpp : 定义控制台应用程序的入口点。
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
#define MAXD 35
int N;
long long int f[MAXD];
void init()
{
    int i;
    memset(f, 0, sizeof(f));
    f[0] = 1;
    f[2] = 3;
    for(i = 4; i <= 30; i += 2)
        f[i] = 4 * f[i - 2] - f[i - 4];
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    init();
    for(;;)
    {
        scanf("%d", &N);
        if(N == -1)
            break;
        printf("%lld\n", f[N]);
    }
    return 0;
}

