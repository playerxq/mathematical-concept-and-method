// leetcode-172-n!��β0�ĸ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class Solution {
public:
    int trailingZeroes(int n) {
       int res = 0;
       for(long long i = 5;n/i>0;i*=5)//����5�ĸ���
	       res+=(n/i);
       return res;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

