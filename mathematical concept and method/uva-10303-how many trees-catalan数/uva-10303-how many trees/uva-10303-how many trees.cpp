// uva-10303-how many trees.cpp : 定义控制台应用程序的入口点。
//f[n] = (4*n-2) * f[n-1] /(n+1)
//catalan

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
int f[1111][3333];
int l[1111];//每个f[i]的长度
void div(int x)//f[x]/(x+1)
{  
    int *t=f[x],y=x+1,cur=0,i;  
    for(i=l[x]-1; i>-1; i--){  
        cur=cur * 10 + t[i];  
        t[i]=cur / y;  
        cur %= y;  
    }  
    for(i=l[x]-1; i>0 && !t[i]; i--);  
	l[x]=i+1;  
}
void mul(int x)
{            //大数乘法  
    int &i=l[x],c=0,y=4*x-2;  
    int *p=f[x-1],*t=f[x];  
    for(i=0; i<l[x-1] || c; i++){  
        c=c+p[i]*y ;  
        t[i]=c%10;  
        c/=10;  
    }  
}
void print(int x){      //打印结果  
    int *p=f[x];  
    for(int i=l[x]-1; i>-1; i--)  
        printf("%d",p[i]);  
    cout<<endl;  
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	memset(f,0,sizeof(f));
	int i;
	f[1][0]=1;  l[1]=1;         //打表  
    for(i=2; i<=1000; i++) {  
        mul(i);     //先乘  
        div(i);     //后除  
    }
	while(scanf("%d",&n)!=EOF)
	{
		print(n);
	}
	return 0;
}

