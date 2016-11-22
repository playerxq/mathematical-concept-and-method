// uva-701-archeologist dilemma.cpp : �������̨Ӧ�ó������ڵ㡣
//2^ans > n * 10^i &&  2^ans < (n + 1) * 10^i  ȡ2�׶��� ����ans����

#include "stdafx.h"


#include <iostream>
#include <cmath>
using namespace std;

double log(double a, double n) {
	return log10(n) / log10(a);
}

int main() {
	double a, b, n;
	while (scanf("%lf", &n) == 1) {
		int ok = 0;
		for (long i = (long)log10(n) + 2; !ok; i++) {//i��log10(n)+2����ö��ֱ�� [a,b)��һ������j
			a = log(2, n) + i * log(2, 10);
			b = log(2, n + 1) + i * log(2, 10);
			for (long j = (long)a; j < b && !ok; j++) {//��aת��Ϊ����j��ʼ ֱ��һ������j����[a,b)
				if (j >= a && j < b) {
					printf("%ld/n", j);
					ok = 1;
					break;
				}
			}
		}
	}
	return 0;
}






