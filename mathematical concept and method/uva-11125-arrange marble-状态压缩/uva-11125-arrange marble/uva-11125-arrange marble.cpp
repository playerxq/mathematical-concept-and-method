// uva-11125-arrange marble.cpp : �������̨Ӧ�ó������ڵ㡣
//����n����ɫ����Ȼ��ÿ����һ������������Щ��ڷų�һȦ��ͬ��������������3�������ڵ���Ⱥ�ĸ�������ͬ�ķ�������

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
#define MAXD 1100000
int f[MAXD], a[5], b[5];
//f[state]//state��4λΪ4������ �ֱ�Ϊpc pn fc fn��֮ǰ��ʯͷ����ɫ �����Լ���βʯͷ����ɫ ���� ��4λΪ8���� ��ǰʣ��ʯͷ������
int dp(int state)
{
	int i, j, k, t, st = state, ans = 0, fc, fn, pc, pn;
	if(f[st]!=-1)
		return f[st];
	fc = st % 4, st /= 4;
    fn = st % 4, st /= 4;
    pc = st % 4, st /= 4;
    pn = st % 4, st /= 4;
	k = 0;//ʣ��ʯͷ��Ŀ
	for(i = 0;i<4;i++)
	{
		b[i] = st%8;
		st/=8;
		k+=b[i];
	}
	if(k == 0)
    {
        if(pc == fc && pn == fn)//����β��
            return f[state] = 1;
        else
            return f[state] = 0;
    }
	for(i = 0;i<4;i++)
	{
		if(i==pc)//���ܵ���֮ǰ����ɫ
			continue;
		for(j = 1;j<=min(3,b[i]);j++)
		{
			if(j==pn)//��Ŀ���ܵ���֮ǰȺ����Ŀ
				continue;
			b[i]-=j;
			for(k = 3,t = 0;k>=0;k--)
			{
				t = t*8+b[k];
			}
			//pn = j pc = i
			t = (((t*4+j)*4+i)*4+fn)*4+fc;
			ans += dp(t);
			b[i]+=j;
		}
	}
	return f[state] = ans;
}
void solve()
{
    int i, j, k, n, res, t;
    memset(a, 0, sizeof(a));
    scanf("%d", &n);
    k = 0;
    for(i = 0; i < n; i ++)//n��ʯͷ �Լ�ÿ�ָ��� n<=4 a[i]<=8
    {
        scanf("%d", &a[i]);
        k += a[i];
    }
    if(!k)
    {
        printf("1\n");
        return ;
    }
	//���ó�ʼ״̬
    for(i = 3, k = 0; i >= 0; i --)
        k = k * 8 + a[i];
    res = 0;
	//��ʼ��fc fnö��  ��pc pn����fc fn ��ֻ��ÿ��ö�ٵ���Ŀ����ɫ������pc pn����
    for(i = 0; i < n; i ++)
        for(j = 1; j <= 3 && j <= a[i]; j ++)//ÿ�鲻����3��
        {//pc = fc = i  pn = fn = j
            t = (((k * 4 + j) * 4 + i) * 4 + j) * 4 + i;
            res += dp(t);
        }
    printf("%d\n", res);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
    memset(f, -1, sizeof(f));
    scanf("%d", &t);
    while(t --)
        solve();
    return 0;
}

