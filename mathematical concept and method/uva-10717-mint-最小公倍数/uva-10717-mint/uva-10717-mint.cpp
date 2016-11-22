// uva-10717-mint.cpp : 定义控制台应用程序的入口点。
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
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 60;

int coin[MAXN];
int n,t;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    while (scanf("%d%d",&n,&t) != EOF && n+t){
        for (int i = 0; i < n; i++)
            scanf("%d",&coin[i]);

        int a,ans,Max,Min;
        for (int d = 0; d < t; d++){
            scanf("%d",&a);
            Max = 0,Min = INF;
            for (int i = 0; i < n-3; i++){
                for (int j = i+1; j < n-2; j++){
                    int m = coin[i]/gcd(coin[i],coin[j])*coin[j];
                    for (int k = j+1; k < n-1; k++){
                        int mm = m/gcd(m,coin[k])*coin[k];
                        for (int l = k+1; l < n; l++){
                            ans = mm/gcd(mm,coin[l])*coin[l];//4个数最小公倍数
                            int x,y;
                            if (a%ans == 0)
                                x = y = a;
                            else x=(a/ans)*ans,y=(a/ans+1)*ans;
                            Max = max(x,Max);
                            Min = min(y,Min);
                        }
                    }
                }
            }
            printf("%d %d\n",Max,Min);
        }
    }
    return 0;
}

