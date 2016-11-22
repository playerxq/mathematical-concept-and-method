// uva-10900-2n-aire.cpp : �������̨Ӧ�ó������ڵ㡣
//
/*
��ҳ�ʼ�Ľ��Ϊ1������n����ʾ��n����Ŀ��t��ʾ˵���һ����Ŀ�ĸ�����t��1֮��
ÿ�����һ���⣬����ѡ�������Ϸ����õ�ǰ���𣻻ش���һ�����⣬��Եĸ���p��t��1֮��
��ԵĻ����𷭱������Ļ�������Ϸ��û�н��������Ӯ�Ľ��������ֵ�����ֵ��
*/
/*
ansΪ��ǰ��õ����Ž�����������ʼ��Ϊ2^(n)������Ϊi=0ʱ��ans
���Ѿ������i����Ŀ�������Ѿ��õ�2^i����i+1���Ը���Ϊp
��i+1��ʱ��p���ʻ��ans����1-p���ʻ�ý���Ϊ0���������Ϊp*ans�����p*ans>2^i�������ڵ�ǰi����Ŀ�Ľ�����ѡ����⡣
����2^i/ans��Ϊp���ٽ�ֵ�����t���ڴ�ֵ����p��Ȼ�����ٽ�ֵ����Ȼѡ����⡣���򽫴��ٽ�ֵ��Ϊt:1���ٽ��������
*/
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
const int N = 35;
double v[N];
double t;
int n;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	v[0] = 1;
	for(int i = 1;i<=30;i++)
		v[i] = v[i-1]*2;//2^i
	while(scanf("%d%lf",&n,&t))
	{
		if(n+t==0)
			break;
		if(fabs(1-t)<1e-9)
			printf("%.3lf\n",v[n]);
		else
		{
			double ans = v[n];//ansΪ��ǰ��õ����Ž�������
			for(int i = n-1;i>=0;i--)//�鿴��i+1����Ŀ�Ƿ��
			{
				double f = v[i]/ans;
				if(f<=t)//�κ�p������ʹ��p*ans>2^i  �ʴ��i+1�� ����pΪt:1��ֵ
				{
					ans = (1+t)/2*ans;//���i+1�⣬��ǰ��õĽ�����i+1��ĸ���p����
				}
				else//p����t:f������  ȡ��i�����ŵ�2^i  ����f:1��i+1�� ȡp=(1+f)/2��ֵ���������� ��ʱ��õĽ�����Ҫ��p����
				{
					ans = ((f - t) / (1 - t)) * v[i] + ((1 - f) / (1 - t)) * (1 + f) / 2*ans;
				}
			}
			printf("%.3lf\n",ans);
		}
	}
	return 0;
}

