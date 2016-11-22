// uva-10157-expression.cpp : �������̨Ӧ�ó������ڵ㡣
//n�������ţ����Ƕ��Ϊd�����ű��ʽ��Ŀ

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
int n,d;
const int MAXSIZE = 300;
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
			if(ans.s[i]>=10)
			{
				ans.s[i]-=10;
				ans.s[i+1]++;
			}
		}
		while(len>1&&ans.s[ans.len-1]==0)
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
bign f[155][155];//f[i][j]Ϊ��i��Ϊֹ��Ȳ�����j������ 
//�����һ�������Լ�������Ե�һ������һ�� �ڲ���k�� ������d-1 ��i�Ի��ֿ� k : i-1-k
//��ʱ��ĿΪf[k][d-1]*f[i-1-k][d] ��k��� 0:n-1
void init()
{
	for(int i = 0;i<=150;i++)
		f[0][i] = 1;
	for(int i = 1; i <= 150; i ++)
            for(int j = 0; j <= 150; j ++)
                f[i][j] = 0;
	for(int i = 1;i<151;i++)
	{
		for(int j = 1;j<151;j++)
		{
			for(int k = 0;k<=i-1;k++)//һ��i������ ��һ�����������i-1��
			{
				bign s = f[k][j-1]*f[i-k-1][j];
				f[i][j] = f[i][j]+s;
			}
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	init();
	while(scanf("%d%d",&n,&d)!=EOF)
	{
		
		if(n%2==1)
			printf("0\n");
		else if(n<=2||d<=1)
		{
			printf("1\n");
		}
		else
		{
			n/=2;//ת��Ϊn��
			bign n1 = f[n][d];
			bign n2 = f[n][d-1];
			bign n3 = n1 -n2;
			n3.put();
		}
	}
	return 0;
}

