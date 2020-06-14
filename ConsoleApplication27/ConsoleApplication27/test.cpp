#define _CRT_SECURE_NO_WARNINGS 1
//自然解法
#include<iostream>
#include<stdio.h>
using namespace std;
//char fun(char x, char y)
//{
//	if (x < y)
//		return x;
//	return y;
//}
//int main()
//{
//	int a = '1', b = '1', c = '2';
//	cout << fun(fun(a, b), fun(b, c));
//	return 0;
//}
//int main()
//{
//	int m = 0123, n = 123;
//	printf("%o %o", m, n);
//	return 0;
//}
class Solution {
public:
	int StrToInt(string str) {
		if (str.empty()) return 0;
		int res = 1;
		if (str[0] == '-')
		{
			res = -1;
			str[0] = '0';
		}
		else if (str[0] == '+')
		{
			res = 1;
			str[0] = '0';
		}
		int sum = 0;
		for (int i = 0; i<str.size(), ++i;)
		{
			if (str[i]<'0' || str[i]>'9')
			{
				sum = 0;
				break;
			}
			sum = sum * 10 + str[i] - '0';
		}
		return res*sum;

	}
};
int main()
{
	int StrToInt(+21474836470);
	return 0;
}