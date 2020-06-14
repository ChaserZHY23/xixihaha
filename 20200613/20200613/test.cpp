#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		int length = str.length();
		int a[100] = { 0 };
		for (int i = 0; i<length; i++)
		{
			a[str[i]] = 1;
		}
		for (int i = 0; i<length; i++)
		{
			if (a[str[i]] == 1)
			{
				cout << str[i];
				a[str[i]] = 0;
			}
		}
		cout << endl;
	}
	return 0;
}
//class Finder {
//public:
//	int findElement(vector<int> A, int n, int x) {
//		// write code here
//		int left = 0;
//		int right = n - 1;
//		int mid = 0;
//		while (left<right)
//		{
//			mid = (left + right) / 2;
//			if (A[mid] == x) return mid;
//			if (A[mid]<x)
//			{
//				if (A[mid]<A[left] && x>A[right])
//				{
//					right = mid - 1;
//				}
//				else left = mid + 1;
//			}
//			else {
//				if (A[mid]>A[left] && x<A[left])
//				{
//					left = mid + 1;
//				}
//				else right = mid - 1;
//			}
//		}
//		return -1;
//	}
//};