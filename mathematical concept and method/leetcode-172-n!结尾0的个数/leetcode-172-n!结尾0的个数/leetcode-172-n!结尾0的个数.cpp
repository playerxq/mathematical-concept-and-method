// leetcode-172-n!结尾0的个数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
    int trailingZeroes(int n) {
       int res = 0;
       for(long long i = 5;n/i>0;i*=5)//查找5的个数
	       res+=(n/i);
       return res;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

