// uva-128-software crc.cpp : 定义控制台应用程序的入口点。
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
#define M 34943
char s[1030];
char ans[5];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(gets(s))
	{
		if(s[0]=='#')
			break;
		int len = strlen(s);
		long long remind = 0;
		if(len==0)
		{
			printf("00 00\n");
			continue;
		}
		for(int i = 0;i<len;i++)
		{
			remind = ((remind<<8)+s[i])%M;
		}
		remind = (remind<<16)%M;
		remind = M - remind;
		int i = 3;
		strcpy(ans,"0000");
		//将remind转为16进制
		while(remind>0)
		{
			if(remind%16<10)
			{
				ans[i--] = remind%16+'0';
			}
			else
				ans[i--] = remind%16 -10+ 'A';
			remind /= 16;
		}
		printf("%c%c %c%c\n", ans[0], ans[1], ans[2], ans[3]);
	}
	return 0;
}

