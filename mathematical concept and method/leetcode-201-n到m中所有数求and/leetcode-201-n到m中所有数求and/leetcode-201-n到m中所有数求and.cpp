// leetcode-201-n到m中所有数求and.cpp : 定义控制台应用程序的入口点。
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

