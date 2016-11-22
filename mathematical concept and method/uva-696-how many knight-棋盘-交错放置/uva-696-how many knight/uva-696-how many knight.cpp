// uva-696-how many knight.cpp : 定义控制台应用程序的入口点。
//1.min(n,m) = 1，则摆放max(n,m)；2.min(n,m) = 2，则每2*2个为一组，奇数组填满偶数组放空；
//3.其他，按照行列加和的奇偶性放入相同奇偶性的格子必不冲突，即(m*n+1)/2。

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
int f( int n, int m )  
{  
    if ( n < m ) return f( m, n );  
    if ( m == 1 ) return n;  
    if ( m == 2 ) return n/4*4+(n%4<3?n%4:2)*2;  
    return (n*m+1)/2;  
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;  
    while ( scanf("%d%d",&n,&m) && n+m ) {  
        int ans = f(n,m);  
        printf("%d ",ans);  
        if ( ans > 1 ) printf("knights");   
        else printf("knights");   
        printf(" may be placed on a %d row %d column board.\n",n,m);  
    }
	return 0;
}

