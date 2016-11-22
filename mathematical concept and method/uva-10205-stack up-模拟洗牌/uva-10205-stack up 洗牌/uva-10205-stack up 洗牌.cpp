// uva-10205-stack up 洗牌.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//
// 直接根据题意模拟洗牌的过程即可。
	
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
	
#define TOTAL 52	// 一副牌的的数量。
#define SUITS 13	// 一副牌牌面值的种数。
	
// 按洗牌方法交换牌的位置。
void swap(int card[], vector < int > shuffle)
{
	int tmp[TOTAL];
	for (int i = 0; i < TOTAL; i++)
		tmp[i] = card[shuffle[i] - 1];
	memcpy(card, tmp, TOTAL * sizeof(int));
}
	
// 显示牌的面值及花色。
void display(int card[])
{
	string value[] = { "2", "3", "4", "5", "6", "7", "8", 
	"9", "10", "Jack", "Queen", "King", "Ace" };
	string suit[] = { "Clubs", "Diamonds", "Hearts", "Spades" };

	for (int i = 0; i < TOTAL; i++)
        {
                cout << value[(card[i] - 1) % SUITS] << " of ";
                cout << suit[(card[i] - 1) / SUITS] << endl;
        }
}
	
int main(int argc, char *argv[])
{
	string line;
	int cases, means, cards[TOTAL];
	vector < vector < int > > shuffles;
	vector < vector < int > >::iterator start;
	
	cin >> cases;
	while (cases--)
	{
		// 读入洗牌术的具体操作。
		cin >> means;
		shuffles.clear();
		shuffles.resize(means);
		for (start = shuffles.begin(); start < shuffles.end(); start++)
			(*start).resize(TOTAL);
	
		start = shuffles.begin();
		for (int j = 0; j < means; j++)//每一种洗牌方式
		{
			for (int k = 0; k < TOTAL; k++)//读入具体洗牌方式
				cin >> (*start)[k];
			start++;
		}
		
		// 使用 1 - 52 的整数来表示每一张牌，牌面值按 2 - A，花色按黑桃，方块，红心，
		// 梅花的顺序。
		for (int m = 0; m < TOTAL; m++)
			cards[m] = (m + 1);
	
		cin.ignore();
	//对shuffle[k]种洗牌方式，shuffle[k][i]-1号牌放入i号位置
		while (getline(cin, line), line.length())
			swap(cards, shuffles[atoi(line.data()) - 1]);
	
		// 显示交换后牌的面值及花色。
		display(cards);
	
		if (cases)
			cout << endl;
	}
	
	return 0;
}

