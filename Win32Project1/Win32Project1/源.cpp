#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
bool Huiwen(string str1)   //判断回文
{
	int length = str1.length();
	for (int i = 0; i<length; i++)
	{
		if (str1[i] != str1[length - 1])
			return false;
		length = length - 1;
	}
	return true;
}
int main()
{
	string str1, str2, temp;
	int count, len;
	while (cin >> str1 >> str2)
	{
		count = 0;
		temp = str1;
		len = str1.length() + 1;
		for (int i = 0; i<len; i++)
		{
			str1 = temp;
			str1.insert(i, str2);   //在A字符串中以此插入B字符串
			if (Huiwen(str1))       //判断是否是回文
				count = count + 1;    //统计回文    
		}
		cout << count << endl;
	}
	return 0;
}