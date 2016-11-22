// uva-11027-palindrome permutation.cpp : �������̨Ӧ�ó������ڵ㡣
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
long long N;
char b[35];
int a[35];
int flag;
long long int A(int k)//�׳�
{
    int i;
    long long int ans = 1;
    for(i = 2; i <= k; i ++)
        ans *= i;
    return ans;
}
long long int C(int m, int n)//���
{
    int i;
    long long int ans = 1;
    if(m - n < n)
        n = m - n;
    for(i = 1; i <= n; i ++)
        ans = ans * (m - n+ i) / i;
    return ans;
}
long long int calculate(int sur)//��������
{
    int i;
    long long int ans = 1;
    while(sur)
    {
        ans *= sur;
        -- sur;
    }
    for(i = 1; i <= 26; i ++)//sur!/(a[i]!*a[i+1]!...)
        if(a[i])
            ans /= A(a[i]);
    return ans;
}
void dfs(int sur, long long int total)
{
    int i, j, k;
    long long int ans;
    if(sur == 0)
    {
        if(total > 1)
            printf("XXX");
        else if(flag)//��һ�������ε���ĸ
            printf("%c", flag + 'a' - 1);
        return ;
    }
    for(i = 1; i <= 26; i ++)
        if(a[i])//��i+'a'�ŵ�����  ��һ��ʱa[i]--
        {
            -- a[i];
            ans = calculate(sur - 1);//һ�뻹ʣsur-1����ĸ �����������
            if(ans < total)//������  �ٻ����i+'a'�ŵ�����
                total -= ans;
            else//
            {
                printf("%c", i + 'a' - 1);//һ�˷�i+'a'
                dfs(sur - 1, total);
                printf("%c", i + 'a' - 1);
                return ;
            }
            ++ a[i];
        }
    printf("XXX");
}
void solve()
{
    int i, j, k;
    k = flag = 0;
    memset(a, 0, sizeof(a));
    for(i = 0; b[i]; i ++)
        a[b[i] - 'a' + 1] ++;//��ĸʹ�ô���
    for(i = 1; i <= 26; i ++)
        if(a[i] % 2)
        {
            flag = i;
            k ++;
        }
    if(k > 1)//����2����ĸ������ �޻��Ĵ�
    {
        printf("XXX");
        return ;
    }
    k = 0;
    for(i = 1; i <= 26; i ++)
    {
        a[i] /= 2;
        k += a[i];
    }//kΪ������һ�����ĸ��
    dfs(k, N);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int ncase = 1;
	while(T--)
	{
		scanf("%s%lld",b,&N);
		printf("Case %d: ", ncase++);
        solve();
        printf("\n");
	}
	return 0;
}

