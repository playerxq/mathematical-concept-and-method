// uva-10079-pizza cut.cpp : �������̨Ӧ�ó������ڵ㡣
//��n��������f(n)��ǰn-1����������n-1�����㽫��n���ֳ�n�� һ��һ������  ���n������  f(n) = n+f(n-1) = 1+n(n+1)/2

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

