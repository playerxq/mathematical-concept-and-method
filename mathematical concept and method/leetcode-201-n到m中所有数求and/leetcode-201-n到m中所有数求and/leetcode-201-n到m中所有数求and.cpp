// leetcode-201-n��m����������and.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
    return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

