#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
bool sum(int n1, int n2, int n3, int n4)
{
	int num1 = n1 + n2 + n3 + n4;
	if (num1 = 24)
	{
		return true;
	}
	else return false;
}
int main()
{
	int n1, n2, n3, n4;
	while (cin >> n1 >> n2 >> n3 >> n4)
	{
		sum(n1, n2, n3, n4);
	}
}