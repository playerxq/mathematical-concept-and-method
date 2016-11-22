// uva-701-archeologist dilemma.cpp : 定义控制台应用程序的入口点。
//2^ans > n * 10^i &&  2^ans < (n + 1) * 10^i  取2底对数 整数ans即可

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
		for (long i = (long)log10(n) + 2; !ok; i++) {//i从log10(n)+2向上枚举直到 [a,b)有一个整数j
			a = log(2, n) + i * log(2, 10);
			b = log(2, n + 1) + i * log(2, 10);
			for (long j = (long)a; j < b && !ok; j++) {//从a转化为整数j开始 直到一个整数j属于[a,b)
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






