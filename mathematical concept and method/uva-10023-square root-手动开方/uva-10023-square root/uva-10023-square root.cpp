#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#define max(a,b) (a)>(b)?(a):(b)
const int N = 1005;

struct bign {
	int s[N];
	bign () {
		memset(s, 0, sizeof(s));
	}
	bign (int number) {*this = number;}
	bign (const char* number) {*this = number;}

	void put();
	bign mul(int d);
	void del();

	bign operator = (char *num) {//高位于高索引
		s[0] = strlen(num);
		for (int i = 1; i <= s[0]; i++)
			s[i] = num[s[0] - i] - '0';
		return *this;
	}

	bign operator = (int num) {
		char str[N];
		sprintf(str, "%d", num);
		return *this = str;
	}

	bool operator < (const bign& b) const {
		if (s[0] != b.s[0])
			return s[0] < b.s[0];
		for (int i = s[0]; i; i--)
			if (s[i] != b.s[i])
				return s[i] < b.s[i];
		return false;
	}
	bool operator > (const bign& b) const { return b < *this; }
	bool operator <= (const bign& b) const { return !(b < *this); }
	bool operator >= (const bign& b) const { return !(*this < b); }
	bool operator != (const bign& b) const { return b < *this || *this < b;}
	bool operator == (const bign& b) const { return !(b != *this); }

	bign operator + (const bign& c) {
		int sum = 0;
		bign ans;
		ans.s[0] = max(s[0], c.s[0]);

		for (int i = 1; i <= ans.s[0]; i++) {
			if (i <= s[0]) sum += s[i];
			if (i <= c.s[0]) sum += c.s[i];
			ans.s[i] = sum % 10;
			sum /= 10;
		}

		while (sum) {
			ans.s[++ans.s[0]] = sum % 10;
			sum /= 10;
		}
		return ans;
	}

	bign operator * (const bign& c) {
		bign ans;
		for (int i = 1; i <= c.s[0]; i++) {
			int d = c.s[i], sum = 0;
			for (int j = 1; j <= s[0]; j++) {
				sum = d * s[j] + sum + ans.s[i + j - 1];
				ans.s[i + j - 1] = sum % 10;
				sum /= 10;
			}
			int t = s[0] + i - 1;

			while (sum) {
				++t;
				sum += ans.s[t];
				ans.s[t] = sum % 10;
				sum /= 10;
			}
			ans.s[0] = max(ans.s[0], t);
		}
		return ans;
	}

	bign operator - (const bign& c) {
		bign ans = *this;
		for (int i = 1; i <= c.s[0]; i++) {
			if (ans.s[i] < c.s[i]) {
				ans.s[i] += 10;
				ans.s[i + 1] -= 1;
			}
			ans.s[i] -= c.s[i];
		}

		ans.del();
		return ans;
	}

	int operator / (const bign& c) {
		int ans = 0;
		bign d = *this;
		while (d >= c) {
			d = d - c;
			ans++;
		}
		return ans;
	}
};

void Sqrt(char *num) {
	int len = strlen(num), i;
	bign ans = 0, b, c, d;
	//先找到第一个节的最大的根号值
	if (len % 2) {//最高一位
		i = 1;
		int cur = num[0] - '0';
		ans = (int)sqrt((double)cur);
		d = cur;
	} else {//最高2位
		int cur = (num[0] - '0') * 10 + num[1] - '0';
		ans = (int)sqrt((double)cur);
		d = cur;
		i = 2;
	}
	//对第一节第二节特殊处理
	//此时ans为第一节的根号值 d为第一节的余值
	if (i < len) {
		int cur = (num[i] - '0') * 10 + num[i + 1] - '0';//取2位
		i += 2;
		c = cur;
		d = d.mul(2) + c;//d*100+c为第一节余值+第二节
		
		//ans*ans*100为第一节得到的值得扩展
		//d-ans*ans*100为第一个差值目标c
		//找最大的cur使得(cur+ans*20)*cur<=c
		//则cur必然小于c/ans*20
		c = ans * ans;
		c = d - c.mul(2);//c为新的余值
		b = ans + ans;
		b.mul(1);//ans*20=b

		cur = c / b;

		while (1) {
			bign t = cur * cur;//b = cur(cur+ans*20)
			b = ans * (20 * cur) + t;

			b.del();
			if (b <= c) {//得到最大的cur使得cur(cur+20*ans)<=c
				d = c - b;//新的差值目标
				t = cur;//保存得到的结果
				ans = ans.mul(1) + t;//更新结果
				break;
			} else if (cur){
				cur--;
			} else
				break;
		}
	}

	while (i < len) {//重复
		int cur = (num[i] - '0') * 10 + num[i + 1] - '0';
		i += 2;
		c = cur;
		d = d.mul(2) + c;//d为上一次计算的余数 d*100+c新的被除数

		b = ans + ans;
		b.mul(1);//b = ans*20
//cur(cur+ans*20)<=d  故cur<d/ans*20
		cur = d / b;

		while (1) {
			bign t = cur * cur;
			b = ans * (20 * cur) + t;//b = cur(cur+20*ans)

			b.del();
			if (b <= d) {
				d = d - b;//更新d
				t = cur;
				ans = ans.mul(1) + t;
				break;
			} else if (cur){
				cur--;
			} else
				break;
		}
	}

	ans.put();
	printf("\n");
}

int main () {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int cas;
	char num[N];
	scanf("%d", &cas);
	while (cas--) {
		scanf("%s", num);
		Sqrt(num);
		if (cas) printf("\n");
	}
	return 0;
}

void bign::put() {
	if (s[0] == 0)
		printf("0");
	else
		for (int i = s[0]; i; i--)
			printf("%d", s[i]);
}

bign bign::mul(int d) {//bign*10^d
	s[0] += d;
	for (int i = s[0]; i > d; i--)
		s[i] = s[i - d];
	for (int i = d; i; i--)
		s[i] = 0;
	return *this;
}

void bign::del() {//消除高位0
	while (s[s[0]] == 0) {
		s[0]--;
		if (s[0] == 0) break;
	}
}