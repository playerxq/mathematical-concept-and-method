// uva-11029-leading and trailing.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cmath>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
using namespace std;
int n,k;
int lead,trail;
int solve_trail(int n, int k)  
{  
    if(k==0) return 1;  
    if(k==1) return n%1000;  
    int a = solve_trail(n,k/2);  
    int ans = a*a;  
    if(k%2) ans = n%1000*ans;  
    return ans%1000;  
}
//����x=123456=1.23456*10^5
//logx = log(1.23456)+5
//q-(int)q=log(1.23456)
//log(1.23456)+2��10��ȡ����Ϊ123
int solve_lead(int n, int k)
{
	double q = k*log10((double)n);  
    double ans = pow(10,2+q-(int)q);  //q-(int)q�õ�n�Ŀ�ѧ��������С�����ֵ�k�η���logֵ  ����10���׵õ�С�����ֵ�k�η�
    return (int)ans; //�ٳ�10^2ȡ���õ����3λ
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		trail = solve_trail(n,k);
		lead = solve_lead(n,k);
		printf("%3d...%03d\n",lead,trail); 
	}
	return 0;
}

