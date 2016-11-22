// uva-10205-stack up ϴ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//
// ֱ�Ӹ�������ģ��ϴ�ƵĹ��̼��ɡ�
	
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
	
#define TOTAL 52	// һ���Ƶĵ�������
#define SUITS 13	// һ��������ֵ��������
	
// ��ϴ�Ʒ��������Ƶ�λ�á�
void swap(int card[], vector < int > shuffle)
{
	int tmp[TOTAL];
	for (int i = 0; i < TOTAL; i++)
		tmp[i] = card[shuffle[i] - 1];
	memcpy(card, tmp, TOTAL * sizeof(int));
}
	
// ��ʾ�Ƶ���ֵ����ɫ��
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
		// ����ϴ�����ľ��������
		cin >> means;
		shuffles.clear();
		shuffles.resize(means);
		for (start = shuffles.begin(); start < shuffles.end(); start++)
			(*start).resize(TOTAL);
	
		start = shuffles.begin();
		for (int j = 0; j < means; j++)//ÿһ��ϴ�Ʒ�ʽ
		{
			for (int k = 0; k < TOTAL; k++)//�������ϴ�Ʒ�ʽ
				cin >> (*start)[k];
			start++;
		}
		
		// ʹ�� 1 - 52 ����������ʾÿһ���ƣ�����ֵ�� 2 - A����ɫ�����ң����飬���ģ�
		// ÷����˳��
		for (int m = 0; m < TOTAL; m++)
			cards[m] = (m + 1);
	
		cin.ignore();
	//��shuffle[k]��ϴ�Ʒ�ʽ��shuffle[k][i]-1���Ʒ���i��λ��
		while (getline(cin, line), line.length())
			swap(cards, shuffles[atoi(line.data()) - 1]);
	
		// ��ʾ�������Ƶ���ֵ����ɫ��
		display(cards);
	
		if (cases)
			cout << endl;
	}
	
	return 0;
}

