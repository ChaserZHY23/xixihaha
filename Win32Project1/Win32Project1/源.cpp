#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
using namespace std;
bool Huiwen(string str1)   //�жϻ���
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
			str1.insert(i, str2);   //��A�ַ������Դ˲���B�ַ���
			if (Huiwen(str1))       //�ж��Ƿ��ǻ���
				count = count + 1;    //ͳ�ƻ���    
		}
		cout << count << endl;
	}
	return 0;
}