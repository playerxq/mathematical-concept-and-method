// uva-571-jugs.cpp : 定义控制台应用程序的入口点。

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
struct node
{
	int v[2];
} q[1050*10500];
int fa[1050*10500];  
int f[1050*10500];  
bool vis[1010][1010]; 
int jug[2],goal;
char answer[10][100] = {"fill A","fill B","empty A","empty B","pour A B","pour B A"};
void output(int i)
{
	if(!i)
		return;
	output(fa[i]);
	printf("%s\n",answer[f[i]]);
}
void solve()
{
	node cur;
	int front = 0;
	int rear = 1;
	q[0].v[0] = 0, q[0].v[1] = 0, fa[1] = 0;  
    vis[0][0] = 1; 
	while(front<rear)
	{
		cur = q[front];
		int ca = cur.v[0];
		int cb = cur.v[1];//当前两杯状态
		if(ca!=jug[0]&&vis[jug[0]][cb]==0)//第一个杯子没满 将第一个倒满
		{
			vis[jug[0]][cb]==1;
			cur.v[0] = jug[0];
			cur.v[1] = cb;
			f[rear] = 0;//采用的措施描述
			fa[rear] = front;
			if(cur.v[1]==goal)
				break;
			q[rear++] = cur;
		}
		if(cb!=jug[1]&&vis[ca][jug[1]]==0)
		{
			vis[ca][jug[1]]==1;
			cur.v[0] = ca;
			cur.v[1] = jug[1];
			f[rear] = 1;
			fa[rear] = front;
			if(cur.v[1]==goal)
				break;
			q[rear++] = cur;
		}
		if(ca&&vis[0][cb]==0)
		{
			vis[0][cb]==1;
			cur.v[0] = 0;
			cur.v[1] = cb;
			f[rear] = 2;
			fa[rear] = front;
			if(cur.v[1]==goal)
				break;
			q[rear++] = cur;
		}
		if(cb&&vis[ca][0]==0)
		{
			vis[ca][0]==1;
			cur.v[0] = ca;
			cur.v[1] = 0;
			f[rear] = 3;
			fa[rear] = front;
			if(cur.v[1]==goal)
				break;
			q[rear++] = cur;
		}
		if(ca&&cb!=jug[1])
		{
			if(jug[1]>=ca+cb&&vis[0][ca+cb]==0)//全倒
			{
				cur.v[1] = ca+cb;
				cur.v[0] = 0;
				f[rear] = 4;
				fa[rear] = front;
				vis[0][ca+cb] = 1;
				if(cur.v[1]==goal)
					break;
				q[rear++] = cur;
			}
			else if(ca+cb>=jug[1]&&!vis[ca+cb-jug[1]][jug[1]])  
            {  
                cur.v[0] = ca+cb-jug[1];  
                cur.v[1] = jug[1];  
                f[rear] = 4;  
                fa[rear] = front;  
                vis[ca+cb-jug[1]][jug[1]] = 1;  
                if(cur.v[1] == goal) break;  
                q[rear++] = cur;  
            }
		}
		if(cb&&ca!=jug[0])
		{
			if(jug[0]>=ca+cb&&vis[ca+cb][0]==0)//全倒
			{
				cur.v[0] = ca+cb;
				cur.v[1] = 0;
				f[rear] = 5;
				fa[rear] = front;
				vis[ca+cb][0] = 1;
				if(cur.v[1]==goal)
					break;
				q[rear++] = cur;
			}
			else if(ca+cb>=jug[0]&&!vis[jug[0]][ca+cb-jug[0]])  
            {  
                cur.v[0] = jug[0];  
                cur.v[1] = ca+cb-jug[0];  
                f[rear] = 5;  
                fa[rear] = front;  
                vis[jug[0]][ca+cb-jug[0]] = 1;  
                if(cur.v[1] == goal) break;  
                q[rear++] = cur;  
            }
		}
		front++;
	}
	output(rear);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d%d%d",&jug[0],&jug[1],&goal)!=EOF)
	{
		memset(vis, 0, sizeof(vis)); 
		solve();
		printf("success\n");
	}
	return 0;
}

