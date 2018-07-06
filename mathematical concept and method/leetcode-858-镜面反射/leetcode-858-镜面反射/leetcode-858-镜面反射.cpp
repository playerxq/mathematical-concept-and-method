// leetcode-858-æµ√Ê∑¥…‰.cpp : Defines the entry point for the console application.
//
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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class Solution {
public:
	int gcd(int a, int b)
	{
		if (b)
			return gcd(b,a%b);
		return a;
	}
	int mirrorReflection(int p, int q) {
		int m = p*q / gcd(p,q);
		int k = m / p;
		int n = m / q;
		if (k % 2 && n % 2 == 0)
			return 2;
		if (k % 2 && n % 2)
			return 1;
		if (k % 2 == 0 && n % 2)
			return 0;
		return -1;
	}
};

int main()
{
    return 0;
}

