// uva-10277-boast red sock.cpp : 定义控制台应用程序的入口点。
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
long long gcd(long long a, long long b) {  
    return b == 0 ? a : gcd(b, a % b);  
}  
 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	long long p,q;
	while(scanf("%lld%lld",&p,&q))
	{
		if(p+q==0)
			break;
		if(p==q)
		{
			printf("2 0\n");
		}
		else if(p==0)
			printf("0 2\n");
		else
		{
			long long g = gcd(p,q);
			p/=g;
			q/=g;
			long long i,j;
			for(i = 2;i<=50000;i++)
			{
				if(i*(i-1)%q==0)
				{
					long long n = i*(i-1)/q;
					long long m = n*p;
					j = sqrt((long double)m+0.5);
					if(j*(j+1)==m&&j+1>=2)
						break;
				}
			}
			if (i <= 50000)  
                printf("%lld %lld\n", j + 1, i - j - 1);  
            else  
                printf("impossible\n");
		}
	}
	return 0;
}

