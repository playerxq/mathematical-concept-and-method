// uva-557-burger.cpp : 定义控制台应用程序的入口点。
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
#define MAXD 100010
double f[MAXD];
void prepare()
{
    int i, n;
    f[2] = 1;
    for(i = 4; i <= 100000; i ++)
        f[i] = f[i - 2] * (i - 3) / (i - 2);
}
int main()
{
    int t, n;
    prepare();
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d", &n);
        printf("%.4lf\n", 1 - f[n]);
    }
    return 0;
}

