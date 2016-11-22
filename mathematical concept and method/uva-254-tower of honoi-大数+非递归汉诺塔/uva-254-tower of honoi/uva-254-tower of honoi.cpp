// uva-254-tower of honoi.cpp : 定义控制台应用程序的入口点。
//n个盘子完全移动到另一个柱子上需要2^n-1步
//奇数步将盘子移到顺时针下一个柱子  偶数步移动顺时针下两个柱子  因此n为奇数 可以再2^n-1步将所有盘子移动到
//开始柱子的顺时针下个柱子  n为偶数将移动到下两个柱子

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
int a[5];//每个柱子的盘子个数
const int MAXSIZE = 400;
struct bign
{
	int s[MAXSIZE];
	int len;
	bign()
	{
		memset(s,0,sizeof(s));
		len = 1;
	}
	bign operator = (const char* num)//高位在后  低位在前
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
	bign(char* n)
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
bign d[110];
int n;
bign m;
void init()
{
	d[0] = 1;
	for(int i = 1;i<110;i++)
		d[i] = d[i-1]*2;
}
void dfs(int s, int t ,int n, bign m)//s->t 用m步移动n个盘子
{
	if(n==1)
	{
		if(m==0)
		{
			a[s]++;
		}
		else
		{
			a[t]++;
		}
		return;
	}
	int k = 0;
    for(int i = 0; i < 3; i ++)//中转柱
	{
       if(i!=s&&i!=t)
	   {
          k = i;
		  break;
	   }
	}
	if(m>=d[n-1])//将n-1个盘子移到中间的柱子k上
    {
        ++ a[t];//最后一个盘子移到a[t]上
        m = m-d[n-1];//移动n-1个盘子后再移动一次最后盘子  用了2^(n-1)-1+1步
        dfs(k, t, n - 1, m);//剩余n-1个移到最终柱子上
    }
    else//不够移动最后一个盘子
    {
        ++ a[s];//留在起始柱子上 a[s]++  考虑剩余的盘子
        dfs(s, k, n - 1, m);//为使得最后盘子能移到t上  必须将n-1个盘子移到中间柱子上(即使此时最后盘子留在s上)
    }
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		char s[110];
		scanf("%s",s);
		m = s;
		for(int i = 0; i < 3; i ++)
            a[i] = 0;
		dfs(0, 2, n, m);
        if(n % 2 == 0)
            printf("%d %d %d\n",a[0],a[1],a[2]);
        else
            printf("%d %d %d\n",a[0],a[2],a[1]);
	}
	return 0;
}

