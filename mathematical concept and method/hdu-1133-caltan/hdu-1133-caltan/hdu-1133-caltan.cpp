// hdu-1133-caltan.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int max_len = 2050010;
const int maxx = 205;
#define BASE 10 
int fac_len[205];
int res[2050010],n,m;
void mul(int* a, int b, int& len)
{
	int c = 0;
	for(int i = 0;i<len;i++)
	{
		int temp = a[i]*b+c;
		a[i] = temp%BASE;
		c = temp/BASE;
	}
	while(c)
	{
		a[len++] = c%10;
		c/=10;
	}
}
void div(int* a, int b,int& len)
{
	int c = 0;
	for(int i = len-1;i>=0;i--)
	{
		int temp = (c*BASE+a[i]);
		a[i] = temp/b;
		c = temp%b;
	}
	while(a[len-1]==0)
		len--;
}
int fact[205][max_len];  
void setFact ()  //求出0-200的阶乘值   
{  
	memset(fac_len,0,sizeof(fac_len));
	fac_len[0]=fac_len[1]=1;
     fact[0][0] = fact[1][0] = 1;  
     for ( int i = 2; i <= 200; ++ i )  
     {  
           memcpy ( fact[i] , fact[i-1] , fac_len[i-1]* sizeof ( int ) );  
		   fac_len[i]=fac_len[i-1];
           mul( fact[i] , i , fac_len[i]);   
     }   
} 
int len;
void outPut ( int* ctl )  
{  
     int i = 0;              
     for(int i = len-1;i>=0;i--)    
     {  
         printf( "%d", ctl[i] );     
     }   
     putchar ( '\n' );   
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int ca = 1;
	setFact();
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m+n==0)
			break;
		printf ( "Test #%d:\n",ca++ );  
        if ( n > m )  
        {  
             puts ( "0" );  
             continue;   
        }
		memcpy ( res , fact[m+n] , fac_len[m+n] * sizeof ( int ) );
		len = fac_len[m+n];
		mul( res, m+1-n, len );
		div( res, m+1, len);
		outPut ( res );
	}
}

