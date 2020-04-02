#define _CRT_SECURE_NO_WARNINGS 1
//类的定义
//第一种直接在类中包含定义和声明
#include<iostream>
#include<stdio.h>
using namespace std;
//class person
//{
//public:
//	void showinfo()
//	{
//		//cout << _name << _sex << _age << endl;
//	}
//public:
//	char* _name;
//	char* _sex;
//	int _age;
//};
//void Test()
//{
//	person man;
//	man._name = "zhanghuanyu";
//	man._age = 20;
//	man._sex = "nan";
//}
class date
{
public:
	void dispiay()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	void setdate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	date d1, d2;
	d1.setdate(2020, 03, 19);
	d1.dispiay();
	d2.setdate(2020, 03, 20);
	d2.dispiay();
	return 0;
}