// uva-138-street number.cpp : 定义控制台应用程序的入口点。
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
long long h[10];
long long ter[10];
long long n;
int main()
{
	//freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	n = 3;
	int cnt = 0;
	while(1)
	{
		if(cnt==10)
			break;
		if(cnt==5)
		{
			int s = 5;
		}
		long long temp = sqrt((double)n*(n+1)/2);
		if(temp*temp==n*(n+1)/2)
		{
			h[cnt] = temp;
			ter[cnt++] = n;
		}
		n++;
	}
	for (int i = 0; i < 10; ++i)  
        printf("printf(\"%%10d%%10d\\n\", %I64d, %d);\n", h[i], ter[i]); 
	return 0;
}
