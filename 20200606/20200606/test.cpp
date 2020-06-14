//#define _CRT_SECURE_NO_WARNINGS 1
////#include<iostream>
////using namespace std;
////void main()
////{
////	int n[][3] = { 10,20,30,40,50,60 };
////	int(*p)[3];
////	p = n;
////	cout << p[0][0] << *p[0] + 1 << (*p)[2] << endl;
////}
////#include<stdio.h>
////int main()
////{
////	int x = 1;
////	do {
////		printf("%2d\n", x++);
////	} while (x--);
////	return 0;
////}
//#include<iostream>
//#include<string>
//using namespace std;
//bool Hui(string str)
//{
//	int length = str.length();
//	for (int i = 0; i < length; i++)
//	{
//		if (str[1] != str[length - 1])
//		{
//			return false;
//			length = length - 1;
//		}
//		return true;
//	}
//	int main()
//	{
//		string s1, s2, scatstr;
//		int count;
//		while (cin >> s1 >> s2)
//		{
//			count = 0;
//			scatstr = s1;
//			int len1 = s1.length() + 1;
//			for (int i = 0; i < len1; i++)
//			{
//				s1 = scatstr;
//				s1.insert(i, s2);
//				if (Hui(s1))
//				{
//					count++;
//				}
//			}
//			cout << count << endl;
//		}
//		return 0;
//	}
//}
//
////#include<iostream>
////#include<string>
////using namespace std;
////bool Hui(string str)
////{
////	int length = str.length();
////	for (int i = 0; i<length; i++)
////	{
////		if (str[i] != str[length - 1])
////		{
////			return false;
////			length = length - 1;
////		}
////		return true;
////	}
////	int main()
////	{
////		string s1, s2, scatstr;
////		int count;
////		while (cin >> s1 >> s2)
////		{
////			count = 0;
////			scatstr = s1;
////			int len1 = s1.length() + 1;
////			for (int i = 0; i<len1; i++)
////			{
////				s1 = scatstr;
////				s1.insert(i, s2);
////				if (Hui(s1))
////				{
////					count++;
////				}
////			}
////			cout << count << endl;
////		}
////		return 0;
////	}
////}
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