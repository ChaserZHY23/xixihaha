
#include<iostream>
using namespace std;
//#include<string>
//using namespace std;
//int main()
//{
//    int M,N;
//	cin >> M >> N;
//        string str=" ";
//    string s="0123456789ABCDEF";
//    while(M)
//    {
//        if(M<0);
//        M=-M;
//        cout<<"-";
//        int numbers=M%N;
//        str=str[numbers]+str;
//        M=M/N;
//    }
//	cout << str;
//    return 0;
//}
//
//
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	int M, N;
//	cin >> M >> N;
//	string str = " ";
//	string s = "0123456789ABCDEF";
//	while (M)
//	{
//		if (M<0);
//		M = -M;
//		cout << "-";
//		str = s[M%N] + str;
//		M = M / N;
//	}
//	cout << str;
//	return 0;
//}
void main()
{
	int n[ ][3] = { 10,20,30,40,50,60 };
	int(*p)[3];
	p = n;
	cout << p[0][0] << *p[0] + 1 << (*p)[2] << endl;
}