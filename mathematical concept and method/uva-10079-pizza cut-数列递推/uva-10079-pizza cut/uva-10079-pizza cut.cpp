// uva-10079-pizza cut.cpp : 定义控制台应用程序的入口点。
//切n刀的区域f(n)与前n-1刀的线至多n-1个交点将第n刀分成n段 一段一个区域  多出n个区域  f(n) = n+f(n-1) = 1+n(n+1)/2

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
long long N;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	for(;;)
    {
        scanf("%lld", &N);
        if(N < 0)
            break;
        printf("%lld\n", (N * N + N) / 2 + 1);
    }
    return 0;
}

