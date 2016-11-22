// uva-10183-how many fibs.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <climits>  
#include <algorithm>
using namespace std;
#define UPBOUND 101
vector<string> fibs;
int fibs_compare(string f1, string f2)
{
	if(f1.length()!=f2.length())
		return f1.length()>f2.length()?1:(-1);
	for(int i = 0,j=f2.length()-1;i<=f1.length()-1;i++,j--)
		if(f1[i]!=f2[j])
			return f1[i]>f2[j]?1:(-1);
	return 0;
}
string fibs_add(string f1, string f2)  
{  
   //f1.length() <= f2.length()。  
    string tmp;  
    int carry = 0;  
      
    for (int i = 0; i < f1.length(); i++)  
    {  
        carry = (f1[i] - '0') + (f2[i] - '0') + carry;  
        char c = '0' + carry % 10;  
        tmp.append(1, c);  
        carry = carry / 10;  
    }  
      
    for (int i = f1.length(); i < f2.length(); i++)  
    {  
        carry = (f2[i] - '0') + carry;  
        char c = '0' + carry % 10;  
        tmp.append(1, c);  
        carry = carry / 10;  
    }  
      
    if (carry)  
        tmp.append(1, '1');  
          
    return tmp;  
} 
void fill_fibs()  
{  
    string f1 = "1", f2 = "2";  
      
    fibs.push_back(f1);  
    fibs.push_back(f2);  
      
    while (f2.length() < UPBOUND)  
    {  
        string tmp = fibs_add(f1, f2);  
        f1 = f2;  
        f2 = tmp;  
        fibs.push_back(f2);  
    }  
} 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	fill_fibs();
	string a, b, line;  
    while (getline(cin, line), line.length())  
    {  
        istringstream iss(line);  
        iss >> a >> b;  
          
        if (a == "0" && b == "0")  
            break;  
        else  
        {  
            // 找到大于等于a的斐波那契数在fibs数组的位置。  
            int start, end;  
            for (int i = 0; i < fibs.size(); i++)  
            {  
                if (a.length() > fibs[i].length())  
                    continue;  
                      
                if (fibs_compare(a, fibs[i]) <= 0)  
                {  
                    start = i;  
                    break;  
                }  
            }  
              
            // 找到小于等于b的斐波那契数在fibs数组的位置。  
            for (int i = fibs.size() - 1; i >= 0; i--)  
            {  
                if (b.length() < fibs[i].length())  
                    continue;  
  
                if (fibs_compare(b, fibs[i]) >= 0)  
                {  
                    end = i;  
                    break;  
                }  
            }  
  
            // 输出总个数。  
            cout << (end - start + 1) << endl;  
        }  
    } 
	return 0;
}

