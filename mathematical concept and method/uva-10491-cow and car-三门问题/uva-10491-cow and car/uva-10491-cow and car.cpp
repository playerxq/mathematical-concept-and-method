// uva-10491-cow and car.cpp : 定义控制台应用程序的入口点。
//参赛者会看见三扇关闭了的门，其中一扇的后面有一辆汽车，
//选中后面有车的那扇门可赢得该汽车，另外两扇门后面则各藏有一只山羊。
//当参赛者选定了一扇门，但未去开启它的时候，节目主持人开启剩下两扇门的其中一扇，露出其中一只山羊。
//主持人其后会问参赛者要不要换另一扇仍然关上的门。问题是：换另一扇门会否增加参赛者赢得汽车的概率？
//现在：给你NCOWS只牛，NCARS辆车，NSHOW扇开启的门（ NSHOW < NCOWS）

//问：换门后赢得车的概率是？

//P(赢得汽车)

//=P(最开始选的那扇门后是山羊)*P(在最开始选的那扇门后是山羊的情况下剩下那扇门后是车)
//+P(最开始选的那扇门后是车)*P(在最开始选的那扇门后是车的情况下剩下那扇门后是车)
//设A={最开始选的那扇门后是山羊}，B={第二次选的门后是车}

//则由全概率公式得：
//p(B) = p(A)P(B/A)+p(!A)p(B/!A)
//此题中p(A)=ncow/(ncow+ncar)
//p(B/A)=ncar/(ncow-1-nshow+ncar)  去掉展示出来的cow
//p(B/!A) = ncar-1/(ncar-1-nshow+ncow)  去掉展示出来的那个car
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

int main(void)
{
	int cow, car, show, temp;
	while (~scanf("%d%d%d", &cow, &car, &show))
	{
		temp = cow + car - 1;
		printf("%.5f\n", (double)temp * car / ((temp + 1) * (temp - show)));
	}
	return 0;
}

