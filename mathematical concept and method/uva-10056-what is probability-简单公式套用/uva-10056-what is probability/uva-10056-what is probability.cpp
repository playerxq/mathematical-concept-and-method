// uva-10056-what is probability.cpp : 定义控制台应用程序的入口点。
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
int n,w;
double p;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lf%d",&n,&p,&w);
		w--;
		int i = 1;
		double t = 0;
		double ans = pow(1-p,w)*p;
		while(ans-t>1e-7)
		{
			t = ans;
			ans+=p*pow(1-p,i*n+w);
			i++;
		}
		printf("%.4lf\n",ans); 
	}
	return 0;
}

