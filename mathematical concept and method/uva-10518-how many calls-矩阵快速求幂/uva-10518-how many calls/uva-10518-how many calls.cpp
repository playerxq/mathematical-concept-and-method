// uva-10518-how many calls.cpp : �������̨Ӧ�ó������ڵ㡣
//[F0,F1]=[0��1] , Ҫ��[Fn,Fn+1]


//[F0,F1]  *  |0 1| (n)  =   [Fn,Fn+1] (�����Ǹ߾���)
 //                |1 1|

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
int b[550][2];
long long N,M;
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
	if(n&1) 
    {
        long long tmp;
        tmp=b[c][0];   b[c][0]=b[c][1];     b[c][1]+=tmp;
        tmp=b[c+1][0]; b[c+1][0]=b[c+1][1]; b[c+1][1]+=tmp;
    }
	return;
}
void solve()
{
    memset(b,0,sizeof(b));
    pow_m(N,0);
    printf("%lld\n",(2*b[1][1]-1+M)%M);
    //��֪F(n)��λ��b[1][1]���λ��
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T=0;
    while(scanf("%lld%lld",&N,&M)!=EOF)
    {
        if(!N && !M) break;
        printf("Case %d: %lld %lld ",++T,N,M);
        if(!N) printf("0\n");  //����
        else   solve();
    }
    return 0;
}

