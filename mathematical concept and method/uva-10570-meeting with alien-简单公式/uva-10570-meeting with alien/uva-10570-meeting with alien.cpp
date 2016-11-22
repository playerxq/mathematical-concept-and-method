// uva-10570-meeting with alien.cpp : �������̨Ӧ�ó������ڵ㡣
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
#define MAXD 510
#define INF 0x3fffffff
int a[MAXD], ans[MAXD], g[MAXD], minx, N;
int exchange()
{
    int i, j, k, cnt = 0;
    for(i = 1; i <= N; i ++)
        if(ans[i] != i)
        {
            g[ans[i]] = g[i];//i��g[i]�� ��ans[i]����i��ǰ��λ��g[i] 
            ans[g[ans[i]]] = ans[i];
			ans[i] = i;
			g[i] = i;
            cnt ++;
        }
    return cnt;
}
void solve()
{
    int i, j, k, start, cnt;
    for(i = 1; i <= N; i ++)
        scanf("%d", &a[i]);
    minx = INF;
    for(start = 1; start <= N; start ++)//ö�����
    {
        for(i = 1, j = start; i <= N; i ++, j ++)//��ת����
        {
            if(j > N)
                j = 1;
            ans[i] = a[j];
            g[a[j]] = i;//a[j]���ڵ�ǰ���е�i��λ
        }
        cnt = exchange();
        if(cnt < minx)
            minx = cnt;
    }
    for(start = 1; start <= N; start ++)
    {
        for(i = 1, j = start; i <= N; i ++, j --)//��ת����
        {
            if(j == 0)
                j = N;
            ans[i] = a[j];
            g[a[j]] = i;
        }
        cnt = exchange();
        if(cnt < minx)
            minx = cnt;
    }
    printf("%d\n", minx);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    for(;;)
    {
        scanf("%d", &N);
        if(!N)
            break;
        solve();
    }
    return 0;
}

