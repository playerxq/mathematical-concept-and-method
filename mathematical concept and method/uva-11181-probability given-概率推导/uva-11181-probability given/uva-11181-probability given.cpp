// uva-11181-probability given.cpp : �������̨Ӧ�ó������ڵ㡣
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
    for(i = 0; i < (1 << N); i ++)//ÿ��״̬
    {
        k = 0;
        for(j = 0; j < N; j ++)//��ǰ״̬��1�ĸ���  ���������
            if((1 << j) & i)
                k ++;
        if(k == R)//r��������
        {
            ans = 1;//��ǰ����
            for(j = 0; j < N; j ++)
            {
                if((1 << j) & i)
                    ans *= p[j];
                else
                    ans *= (1 - p[j]);
            }
            rp += ans;//�ۼ�ȫ��״̬��ǡ��R��1ʱ�ĸ���
            for(j = 0; j < N; j ++)//r��������ͬʱ��j������
                if((1 << j) & i)
                    ap[j] += ans;//�����ۼӵ�j��λΪ1ʱ��ȫ��1��R��ʱ�ĸ���
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

