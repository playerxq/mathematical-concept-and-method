// uva-542-france.cpp : �������̨Ӧ�ó������ڵ㡣
//dp[i][left][right]��ʾi�������ڵ�left����right�������õ��ھ��ĸ��ʣ����������Ҫ����dp[i][1][16]��

//mid=(left+right)/2;  

//i��j��[left,right]��������ھ�������i��j��1��16��������ھ���Ҳ���������ܹھ�������ôi��j�ض�������������������

//left<=i<=mid , ��ô��Ҫ�õ�dp[i][left][mid]��dp[j][mid+1][right] 

//mid+1<=i<=right����ô��Ҫ�õ�dp[i][mid+1][right] , dp[j][left][mid]

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
double p[20][20],dp[20][20][20];
char name[20][50];

int main()
{
    int N=16;
    for(int i=1; i<=N; i++) scanf("%s",name[i]);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
        { scanf("%lf",&p[i][j]); p[i][j]/=100; }

    int len,left,right,mid,i,j;

    memset(dp,0,sizeof(dp));
    for(int i=1; i<=N; i++) dp[i][i][i]=1;

    for(len=2; len<=N; len*=2)//������
        for(left=1; left<=N; left+=len)
        {
            right=left+len-1; mid=(left+right)/2;
            for(i=left; i<=mid; i++)//ö��left:mid   mid+1:right�����������ĸ���
                for(j=mid+1; j<=right; j++)
                {
                    dp[i][left][right]+=p[i][j]*dp[i][left][mid]*dp[j][mid+1][right];
                    dp[j][left][right]+=p[j][i]*dp[i][left][mid]*dp[j][mid+1][right];
                }
        }
    for(i=1; i<=N; i++) printf("%-10s p=%.2f%%\n",name[i],dp[i][1][N]*100);
    return 0;
}

