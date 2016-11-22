// uva-991-safe salutation.cpp : 定义控制台应用程序的入口点。
//catalan
//f(n) = (4n-2)f(n-1)/(n+1)

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
#define MAXD 15
long long int h[MAXD];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int i, n, t = 0;
    h[1] = 1;
    for(i = 2; i <= 10; i ++)
        h[i] = h[i - 1] * (4 * i - 2) / (i + 1);
    while(scanf("%d", &n) == 1)
    {
        if(t ++)
            printf("\n");
        printf("%lld\n", h[n]);
    }
    return 0;
}

