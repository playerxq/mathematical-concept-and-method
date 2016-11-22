// uva-10006-carmichael number.cpp : 定义控制台应用程序的入口点。
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
#define M  65010  
bool prime[M];  
void is_prime()  
{  
    int len = sqrt(M+0.5);  
    memset(prime,0,sizeof(prime));  
    for(int i = 2; i <= len; i++) if(prime[i]==0)  
    {  
        for(int j = i*i; j <= M; j+=i) prime[j] = 1;  
    }  
}
int mod(int a, int n, int m)//a^n mod m
{
	if(n==0)
		return 1;
	if(n==1)
		return a%m;
	long long ans = mod(a,n/2,m);
	long long x = ans*ans%m;
	if(n%2)
		x = x*a%m;
	return (int)x;
}
int test_n()
{
	for(int i = 2;i<n;i++)
	{
		if(i!=mod(i,n,n))
			return 1;
	}
	return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	is_prime(); 
	while(scanf("%d",&n)&&n!=0)
	{
		if(prime[n]==0) {printf("%d is normal.\n",n); continue; }
		int flag = test_n();
		if(flag)
		{
			printf("%d is normal.\n",n);
		}
		else
			printf("The number %d is a Carmichael number.\n",n);
	}
	return 0;
}

