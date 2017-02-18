// leetcode-382-reservior sampling.cpp : 定义控制台应用程序的入口点。
//
/*
PROBLEM:

Choose k entries from n numbers. Make sure each number is selected with the probability of k/n
BASIC IDEA:

Choose 1, 2, 3, ..., k first and put them into the reservoir.
For k+1, pick it with a probability of k/(k+1), and randomly replace a number in the reservoir.
For k+i, pick it with a probability of k/(k+i), and randomly replace a number in the reservoir.
Repeat until k+i reaches n
PROOF:

For k+i, the probability that it is selected and will replace a number in the reservoir is k/(k+i)
For a number in the reservoir before (let's say X), the probability that it keeps staying in the reservoir is
P(X was in the reservoir last time) × P(X is not replaced by k+i)
= P(X was in the reservoir last time) × (1 - P(k+i is selected and replaces X))
= k/(k+i-1) × （1 - k/(k+i) × 1/k）
= k/(k+i)
When k+i reaches n, the probability of each number staying in the reservoir is k/n
*/
//k = 1 for this problem
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* h;
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode* head) {
		h = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		ListNode* tmp = h->next;
		int res = h->val;
		int i = 2;
		while (tmp != NULL)
		{
			int t = rand() % i;
			if (t == 0)
				res = tmp->val;
			i++;
			tmp = tmp->next;
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

