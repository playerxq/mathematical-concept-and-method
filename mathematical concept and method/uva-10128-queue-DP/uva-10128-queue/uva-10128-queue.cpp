// uva-10128-queue.cpp : �������̨Ӧ�ó������ڵ㡣
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
#define MAXD 20
int N, P, Q;
long long int f[MAXD][MAXD][MAXD];//f[i][j][k]i���� ǰ��j�� ��k��
//��С����˽���ʱ��i-1���� �����״̬f[i][j][k]
//�������  ����һ��ǰ������ ��ԭ����f[i-1][j-1][k]������
//��β ���Ӻ����� f[i-1][j][k-1]
//�м�  i-2��λ��  ���ᱻ��ס (i-2)*f[i-1][j][k]
void prepare()
{
    int i, j, k;
    memset(f, 0, sizeof(f));
    f[1][1][1] = 1;
    for(i = 2; i <= 13; i ++)
        for(j = 1; j <= i; j ++)
            for(k = 1; k <= i; k ++)
                f[i][j][k] = f[i - 1][j - 1][k] + f[i - 1][j][k - 1] + (i - 2) * f[i - 1][j][k];
}
int main()
{
    int t;
    prepare();
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d%d", &N, &P, &Q);
        printf("%lld\n", f[N][P][Q]);
    }
    return 0;
}

