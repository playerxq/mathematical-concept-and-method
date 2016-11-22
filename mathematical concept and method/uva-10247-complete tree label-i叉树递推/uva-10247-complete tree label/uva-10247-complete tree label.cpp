// uva-10247-complete tree label.cpp : 定义控制台应用程序的入口点。
//k叉树深度为d时进行标号的方案数 节点的标号小于其后代标号

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
int k,d;
int n;
const int MAXSIZE = 10000;
struct bign
{
	int s[MAXSIZE];
	int len;
	bign()
	{
		memset(s,0,sizeof(s));
		len = 1;
	}
	bign operator = (const char* num)
	{
		len = strlen(num);
		for(int i = 0;i<len;i++)
			s[len-i-1] = num[i]-'0';
		return *this;
	}
	bign operator = (const int num)
	{
		char number[200];
		sprintf(number,"%d",num);
		*this = number;
		this->len = strlen(number);
		return *this;
	}
	bign(const int n)
	{
		*this = n;
	}
	bign(char* a)
	{
		*this = n;
	}
	bign operator + (const bign &c){    
        bign sum;  
        int t = 0;  
        sum.len = max(this->len, c.len);  
        for (int i = 0; i < sum.len; i++) {  
            if (i < this->len) t += this->s[i];  
            if (i < c.len) t += c.s[i];  
            sum.s[i] = t % 10;  
            t /= 10;  
        }  
        while (t) {  
            sum.s[sum.len++] = t % 10;  
            t /= 10;  
        }  
           
        return sum;    
    }
	bign operator - (const bign& c)
	{
		bign ans;
		ans.len = max(this->len, c.len);  
        int i;  
		for(i = 0;i<c.len;i++)
		{
			if(this->s[i]<c.s[i])
			{
				this->s[i]+=10;
				this->s[i+1]--;
			}
			ans.s[i] = this->s[i]-c.s[i];
		}
		for (; i < this->len; i++) {  
            if (this->s[i] < 0) {  
                this->s[i] += 10;  
                this->s[i + 1]--;  
            }  
            ans.s[i] = this->s[i];  
        } 
		while(ans.s[ans.len-1]==0)
			ans.len--;
		 if (ans.len == 0) ans.len = 1;  
		return ans;
	}
	bign operator * (int k)
	{
		bign ans;
		int c = 0;
		ans.len = this->len;
		for(int i = 0;i<this->len;i++)
		{
			ans.s[i] += this->s[i]*k;
			while(ans.s[i]>=10)
			{
				ans.s[i]-=10;
				ans.s[i+1]++;
			}
		}
		c = ans.s[ans.len];
		while(c)
		{
			ans.s[ans.len] = c%10;
			c/=10;
			ans.len++;
		}
		return ans;
	}
	bign operator * (const bign& c)
	{
		bign ans;
		ans.len = this->len+c.len;
		for(int i = 0;i<this->len;i++)
		{
			for(int j = 0;j<c.len;j++)
			{
				ans.s[i+j] += this->s[i]*c.s[j];
			}
		}
		for(int i = 0;i<ans.len;i++)
		{
			while(ans.s[i]>=10)
			{
				ans.s[i]-=10;
				ans.s[i+1]++;
			}
		}
		while(ans.len>1&&ans.s[ans.len-1]==0)
			ans.len--;
		return ans;
	}
	bign operator / (const int num)
	{
		bign ans;
		ans.len = this->len;
		int k = 0;
		for(int i = this->len-1;i>=0;i--)
		{
			k = k*10+this->s[i];
			ans.s[i] = k/num;
			k = k%num;
		}
		while(ans.len>1&&ans.s[ans.len-1]==0)
			ans.len--;
		return ans;
	}
	void put() {  
        if (len == 1 && s[0] == 0) {  
            printf("0");  
        } else {  
            for (int i = len - 1; i >= 0; i--)  
                printf("%d", s[i]);  
        }  
		printf("\n");
    }  
	bool operator < (const bign& b) const {  
        if (len != b.len)  
            return len < b.len;  
   
        for (int i = len - 1; i >= 0; i--)  
            if (s[i] != b.s[i])  
                return s[i] < b.s[i];  
        return false;  
    }  
    bool operator > (const bign& b) const { return b < *this; }  
    bool operator <= (const bign& b) const { return !(b < *this); }  
    bool operator >= (const bign& b) const { return !(*this < b); }  
    bool operator != (const bign& b) const { return b < *this || *this < b;}  
    bool operator == (const bign& b) const { return !(b != *this); }  
} ;
bign f[30][30];//f[i][j]为i叉树共j层的方案数
int g[30][30];//i叉树共j层的节点数
//根几点必然是最小标号 之后还剩余g[i][j]-1个 一共有i个g[i][j-1]子树 分别选取 最后每个子树均再乘以子树的方案数f[i][j-1]
//剩余节点数g[i][j]-1一开始为i*g[i][j-1]，即i个深度j-1的i叉子树 之后是i-1个。。。。因此：
//f[i][j] = 连乘c(k*g[i][j-1],g[i][j-1])*(f[i][j-1]) k = i:1

void get_c(bign& ss,int n, int m)
{
	if(m>n-m)
		m = n-m;
	ss = 1;
	for(int i = 1;i<=m;i++)
	{
		ss = ss/i;
		ss = ss*(n-i+1);
	}
}
void init()
{
	for(int i = 1;i<=21;i++)
	{
		f[i][0] = 1;
		g[i][0] = 1;
		for(int j = 1;i*j<=21;j++)
		{
			f[i][j] = 1;
			g[i][j] = g[i][j-1]*i;
			g[i][j]++;
			for(int k = i;k>=1;k--)
			{
				bign ss;
				bign t;
				get_c(ss,k * g[i][j - 1], g[i][j - 1]);
				t = ss*f[i][j-1];
				f[i][j] = t*f[i][j];
			}
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	while(scanf("%d%d",&k,&d)!=EOF)
	{
		bign ans;
		ans = f[k][d];
		ans.put();
	}
	return 0;
}

