// uva-10791-min sum LCM.cpp : 定义控制台应用程序的入口点。
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
int n;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 1;
	while(scanf("%d",&n)&&n)
	{
		printf("Case %d: ",ncase++);
		int sum = 0;
		int tt = n;
		int m = sqrt((double)n)+0.5;
		int t = 2;
		int cnt;
		int k = 0;
		int count = 0;
		while(t<=m)
		{
			if(n%t==0)
			{
				count++;
				cnt = 0;
				int temp = 1;
				while(n%t==0)
				{
					n = n/t;
					temp*=t;
				}
				sum+=temp;
			}
			t++;
		}
		if(tt==n)//n为素数
		{
			printf("%lld\n",(long long) 1 + n);
		}
		else 
		{
            if(n != 1) sum += n;
            else if(count == 1) sum++;
            printf("%d\n",sum);
        }
	}
	return 0;
}

