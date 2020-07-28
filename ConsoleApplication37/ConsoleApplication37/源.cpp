#include<iostream>
#include<set>
using namespace std;
int main()
{
	int num, nums;
	set<int> a;
	while (cin >> num)
	{
		for (int i = 0; i<num; ++i)
		{
			int b;
			cin >> b;
			a.insert(b);
		}
	}
	cin >> nums;
	auto begin = a.begin();
	while (nums != 1)
	{
		begin++;
		nums--;
	}
	cout << *begin << endl;
	return 0;
}