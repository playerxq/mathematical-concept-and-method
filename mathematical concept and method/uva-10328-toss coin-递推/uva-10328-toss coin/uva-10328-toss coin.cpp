// uva-10328-toss coin.cpp : 定义控制台应用程序的入口点。
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
int n,k;
const int MAXSIZE = 200;
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
			if(ans.s[i]>=10)
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
bign f[110][110];//f[i][j]为到i为止H出现连续不超过j的序列个数
//f[i][j] = f[i-1][j]*2  (最后第i个可以H或者T)
//i = j+1 则f[i-1][j]中i-1个全为H  此时去掉1个i也为H情况  f[i][j]--
//i>j+1  i-1:i-j为H  i为H i-j-1为T  f[i-j-2][j]情况去除
void init()
{
	for(int i = 0;i<101;i++)
		f[0][i] = 1;
	f[1][0] = 1;
	for(int i = 1;i<101;i++)
		f[1][i] = 2;
	for(int i = 2;i<101;i++)
	{
		for(int j = 0;j<101;j++)
		{
			f[i][j] = f[i-1][j]*2;//总情况 再去除2个特例
			if(i==j+1)
				f[i][j] = f[i][j]-1;
			else if(i>j+1)
				f[i][j] = f[i][j] - f[i-j-2][j];
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		bign n1 = f[n][n];
		bign n2 = f[n][k-1];
		bign n3 = n1 - n2;
		n3.put();
	}
	return 0;
}

