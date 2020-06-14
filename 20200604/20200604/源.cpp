#include<iostream>
#include<vector>
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int size = numbers.size() / 2;
		sort(numbers.begin(), numbers.end());
		for (int i = 0; i + size<numbers.size(); i++)
		{
			if (numbers[i] == numbers[i + size])
				return numbers[i];
		}
		return 0;
	};
	if (numbers.empty())return 0;
	sort(numbers.begin(), numbers.end());
	int mid = numbers[numbers.size() / 2];
	int count = 0;
	for (int i = 0; i<numbers.size(); ++i)
	{
		if (numbers[i] == mid)++count;
	}
	return (count>numbers.size() / 2) ? mid : 0;