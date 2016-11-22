// uva-10169-urn ball probability.cpp : �������̨Ӧ�ó������ڵ㡣
//��f[i]��ʾǰi�β�����������һ�β���ȡ�����������Ǻ���ĸ���, p[i]�ǵ�i��ȡ�����������Ǻ���ĸ��ʡ�
//����Ƴ�һ���ݹ��ϵ�� f[i+1] = f[i] + (1-f[i])*p[i+1] 
//f[1] = 1/2;
//f[2] = f[1] + (1-f[1])*(1/2)*(1/3);
//f[3] = f[2] + (1-f[2])*(1/3)*(1/4);
//ans = p[1]*p[2]*p[3]*p[4].......p[n]
//ans = 10^i  i = d+a  dΪ����
//ans = 10^d*10^a  -1<a<0 ��0.1<10^a<1 ��С�����������0ֻȡ����10^d d�Ĵ�С
//log(ans) = log(p[1])+log(p[2])+log(p[3])+log(p[4])+........+log(p[n]);
//log(ans)���������֡�

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
#define N 1000005
int n;
double f[N];
double p[N];
double q[N];
void init()
{
	f[0] = 0.0;
	p[0] = 0.0;
	q[0] = 0.0;
	for(int i = 1;i<N;i++)
	{
		p[i] = (double)(1.0*i*(i+1));
		q[i] = q[i-1]+log10(p[i]);
	}
	for(int i = 1;i<N;i++)
	{
		f[i] = f[i-1]+(1-f[i-1])/p[i];
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n)!=EOF)
	{
		printf("%.6lf %d\n",f[n],(int)q[n]); 
	}
	return 0;
}

