// uva-10229-fibnacci.cpp : 定义控制台应用程序的入口点。
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
long long b[200][2];
long long N,M,D;
void pow_m(long long n, int c)
{
	if(n==1)
	{
		b[c][0] = 0;
		b[c][1] = 1;
		b[c+1][0] = b[c+1][1] = 1;
		return;
	}
	pow_m(n/2,c+2);
	long long A=b[c+2][0] , B=b[c+2][1] , C=b[c+3][0] , D=b[c+3][1];
    b[c][0]=  ( A*A+B*C )%M;
    b[c][1]=  ( A*B+B*D )%M;
    b[c+1][0]=( C*A+D*C )%M;
    b[c+1][1]=( C*B+D*D )%M;
	if(n&1) //[A B]*[0 1]
		    //[C D] [1 1]
    {
        long long tmp;
        tmp=b[c][0]%M;   b[c][0]=b[c][1]%M;     b[c][1]+=tmp%M;
        tmp=b[c+1][0]%M; b[c+1][0]=b[c+1][1]%M; b[c+1][1]+=tmp%M;
    }
	return;
}
void solve()
{
	M = 1;
	for(int i = 0;i<D;i++)
		M<<=1;//M=2^D
	pow_m(N,0);
	printf("%lld\n",b[1][0]%M);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%lld%lld",&N,&D)!=EOF)
	{
		if(N==0||D==0)
			printf("0\n");
		else if(N==1)
			printf("1\n");
		else
			solve();
	}
	return 0;
}

