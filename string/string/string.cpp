#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

void swap_int(int* pa, int* pb);
void swap_double(double* pa, double* pb);

namespace bit
{
	// ����ģ��
	template<class T> // template<typename T>
	inline void swap(T& x1, T& x2)
	{
		T tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
}

int main()
{
	
	int a = 0, b = 1;
	double c = 1.1, d = 2.2;
	 swap_int(&a, &b);
	 swap_double(&c, &d);
	char e = 'a', f = 'b';
	bit::swap(a, b);
	bit::swap(c, d);
	bit::swap(e, f);

	return 0;
}

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}


template<class T>
void Func(size_t n)
{
	T* p = new T[n];
	// ...
	delete[] p;
}

int main()
{
	int a1 = 10, a2 = 20;
	double d1 = 10.0, d2 = 20.0;
	Add(a1, a2);
	Add(d1, d2);
	Add(a1, (int)d2);

	Add<int>(a1, d2);
	Add<double>(a1, d2);

	Func<int>(10);

	return 0;
}

int Add(int left, int right)
{
	return left + right;
}
template<class T>
T Add(T left, T right)
{
	return left + right;
}

int main()
{
	Add(1, 2);      // ->�ֳɺ���
	Add(1.1, 2.2);  // ->ģ��ʵ������
	Add<int>(1, 2);

	return 0;
}

namespace bit_c
{
	
	typedef int SLDataType;
	typedef struct SeqList
	{
		SLDataType*   _a;
		size_t _size;
		size_t _capacity;
	}SeqList;

	void SeqListInit(SeqList* ps, size_t n)     // cpp->���캯��
	{}
	void SeqListDestory(SeqList* ps)            // cpp->��������
	{}
	void SeqListPrint(SeqList* ps);
	void SeqListCheckCapacity(SeqList* ps);
	void SeqListPushBack(SeqList* ps, SLDataType x)  // c����������cpp->������ֻ��һ��������ʵ��Ҳ����������һ����������this
	{}
	void SeqListPopBack(SeqList* ps);
}

namespace bit_cpp
{
	template<class T>
	class SeqList
	{
	public:
		SeqList(size_t n = 10)
			:_a(new T[n])
			, _size(0)
			, _capcity(n)
		{}

		~SeqList()
		{
			if (_a != nullptr)
			{
				delete[] _a;
				_size = _capcity = 0;
			}

		}

		void PushBack(T x)
		{
			// ...
		}

		
		T& operator[](size_t i)
		{
			assert(i < _size);

			return _a[i];
		}

		// ...

	private:
		T*           _a;
		size_t      _size;
		size_t      _capcity;
	};
	
}

int main()
{

	bit_c::SeqList seqc;
	bit_c::SeqListInit(&seqc, 10);
	// ...
	bit_c::SeqListPushBack(&seqc, 1);
	bit_c::SeqListPushBack(&seqc, 2);
	bit_c::SeqListPushBack(&seqc, 3);
	bit_c::SeqListDestory(&seqc);


	// CPP��ʹ��˳���
	bit_cpp::SeqList<int> seqcpp1;
	seqcpp1.PushBack(1);
	seqcpp1.PushBack(2);
	seqcpp1.PushBack(3);

	// ����i��λ�õ�����
	cout << seqcpp1[0] << endl;
	// д��i��λ������
	// seqcpp1.operator[](0) = 0;
	seqcpp1[0] = 0;
	seqcpp1[1] = 0;

	bit_cpp::SeqList<double> seqcpp2;
	seqcpp2.PushBack(1.1);
	seqcpp2.PushBack(2.2);
	seqcpp2.PushBack(3.3);


	return 0;
}

#include <iostream>
#include <string>

int main()
{
	std::string s1;
	std::string s2("helloworld");
	std::string s3(s2);  // std::string s3 = s2;
	s1 = s3;

	// �������ַ�ʽ��������
	std::string s4(s3, 5, 5);
	std::string s5(5, 'a');
	
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
	std::cout << s5 << std::endl;

	// ���������һ������ȡ�����е�ÿ���ַ�
	for (size_t i = 0; i < s1.size(); ++i)
	{
		std::cout << s1[i] << " ";
	}
	std::cout << std::endl;


	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;     // �޲ι���
	string s2("hello world");  // ���ι���
	string s3(s2);  // ��������
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	s1 = s3;        // operator=

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	return 0;
}


int main()
{
	string s1;		
	string s2("hello world");
	cout << s1.size() << endl;  // ����������Ϊ����stl�����õ���size()
	cout << s2.size() << endl;
	cout << s1.length() << endl;
	cout << s2.length() << endl;
	cout << s1.capacity() << endl;
	cout << s2.capacity() << endl;
	cout << s1.empty() << endl;
	cout << s2.empty() << endl;
	cout << s2.size() << endl;
	s2.clear();
	cout << s2.size() << endl;

	// ����û��
	cout << s1.max_size() << endl;
	cout << s2.max_size() << endl;

	return 0;
}

 string/vector��������ݵģ�

#include <iostream>
#include <string>
using namespace std;

int main()
{

	string s;
	size_t sz = s.capacity();
	cout << "capacity changed: " << sz << '\n';
	cout << "making s grow:\n";
	s.resize(1000, 'c');
	return 0;
}

int main()
{

	string s("hello world");
	s.resize(5);
	cout << s << endl;
	s.reserve(1000);
	cout << s.capacity() << endl;
	s.reserve(16);
	cout << s.capacity() << endl;

	return 0;
}

 string�Ĵ�ӡ�ͱ���
int main()
{
	string s1("hello world");
	cout << s1 << endl;
	cout << s1.c_str() << endl;

	s1.resize(20);
	s1.push_back('x');
	cout << s1 << endl;
	cout << s1.c_str() << endl;

	return 0;
}

class String
{
public:
	typedef char* iterator;

	iterator begin()
	{
		return nullptr;
	}
};

String s;
String::iterator it = s.begin();

void Func(const string& str)
{
	int value = 0;
	//�ܱ������ʣ����ǲ����޸ķ��ʵ�ֵ
	string::const_iterator it = str.begin();
	while (it != str.end())
	{
		//*it = '1';
		value *= 10;
		value += (*it - '0');
		++it;
	}
	cout << value << endl;
}

int main()
{
	string s("12345");
	int value = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		value *= 10;
		value += (s[i] - '0');
	}
	cout << value << endl;
	value = 0;
	string::iterator it = s.begin();
	while (it != s.end())
	{
		value *= 10;
		value += (*it - '0');
		++it;
	}
	cout << value << endl;
	value = 0;
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		value *= 10;
		value += (*rit - '0');
		++rit;
	}
	cout << value << endl;

	Func(s);

	return 0;
}

int main()
{
	string s("hello world");
	s[0] = 'x'; // s.operator[](0)
	cout << s << endl;

	return 0;
}

int main()
{
	string s("hello world");
	s.push_back('!');        // β��һ���ַ�
	s.append("hello world"); // β���ַ���
	cout << s << endl;
	string s1("hello");
	string s2("world");
	s1 += ' ';
	s1 += "world";
	s1 += ' ';
	s1 += s2;
	cout << s1 << endl;

	return 0;
}

int main()
{
	string file1("string.cpp.zip");
	string file2("string.txt.c.doc");

	size_t pos1 = file1.rfind('.');
	cout << file1.substr(pos1, string::npos) << endl;

	size_t pos2 = file2.rfind('.');
	cout << file2.substr(pos2, file2.size()-pos2) << endl;

	string url1("http://www.cplusplus.com/reference/string/string/find/");
	string url2("https://www.tengxun.com/find/");
	string url3("ftp://www.baidu.com/string/string/find/");

	// ȡ��url�е�����
	size_t urlpos1 = url1.find("://");
	urlpos1 += 3;
	size_t urlend1 = url1.find('/', urlpos1);
	cout << url1.substr(urlpos1, urlend1 - urlpos1)<<endl;

	size_t urlpos2 = url2.find("://");
	urlpos2 += 3;
	size_t urlend2 = url2.find('/', urlpos2);
	cout << url2.substr(urlpos2, urlend2 - urlpos2) << endl;

	size_t urlpos3 = url3.find("://");
	urlpos3 += 3;
	size_t urlend3 = url3.find('/', urlpos3);
	cout << url3.substr(urlpos3, urlend3 - urlpos3) << endl;

	return 0;
}

#include<iostream>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	size_t pos = str.rfind(' ');
	cout << str.size() - pos - 1 << endl;

	int i, j, k;
	cin >> i >> j >> k;
	cout << i << endl;
	cout << j << endl;
	cout << k << endl;

	return 0;
}

#include <string>

int main()
{
	string s1;
	s1 += 'h';
	s1 += "ello";
	cout << s1 << endl;
	s1.insert(0, "world");
	s1.insert(0, " ");
	s1.insert(6, " ");
	cout << s1 << endl;

	s1.erase(s1.begin());
	cout << s1 << endl;
	s1.erase(s1.begin()+5);
	cout << s1 << endl;
	s1.erase(5, 3);
	cout << s1 << endl;

	return 0;
}


#include <string>

int main()
{
	string s1("hello wrold");
	size_t pos = s1.find('x');
	if (pos != string::npos)
	{
		cout << pos << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}

	string s1("hello world");
	string s2("hello world");

	// string operator+ (const string& lhs, const string& rhs);
	string s3 = s1 + s2;
	s1 + "world";
	 "world" + s1; ����������

	 string& operator+= (const string& str);
	string s3 = s1;
	s3 += s2;
	cout << (s1 < s3) << endl;
	cout << (s1 == s3) << endl;
	for (auto e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}

 ��ǳ����
namespace bit
{ 
	// �ַ�����
	// ʵ��һ���򵥵�string��
	class string
	{
	public:
		string()
		{}

		string(const char* str)
		{}

		//string(char* str = nullptr) // ���ﲻ�ܸ�nullptr��strlen(str)�ͱ�����
		string(char* str = "")
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}
		// string copy(s1)
		string(const string& s)
			:_str(new char[strlen(s._str)+1])
		{
			strcpy(_str, s._str);
		}

		// copy = s1
		// s1 = s1
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}

			return *this;
		}

		~string()
		{
			//printf("%p\n",_str);

			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			return _str[pos];
		}

		size_t size() const
		{
			return strlen(_str);
		}

	private:
		char* _str;
	};

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}

		return out;
	}
}

int main()
{
	bit::string s1("world");
	bit::string s2("hello");
	s2[0] = 'x';

	cout << sizeof(s1) << endl;
	cout << sizeof(s2) << endl;

	bit::string copy(s2);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << copy << endl;

	copy = s1;
	s1 = s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << copy << endl;

	return 0;
}
#include <iostream>
#include <assert.h>
using namespace std;
// ��ɾ��ĵ�string��ģ��ʵ��
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		// s1(s2)
		string(const string& s)
		{
			// +1�ǿ��ռ�ʱ��Զ���ָ�\0�࿪һ��
			_str = new char[s._size + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._size;

			/*_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;*/
		}

		// s1 = s2
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[s._size + 1];
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = s._size;
			}

			return *this;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);

			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);

			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* newstr = new char[n + 1];
				strcpy(newstr, _str);
				delete[] _str;
				_str = newstr;

				_capacity = n;
			}
		}

		void resize(size_t n, char ch = '\0')
		{
			if (n < _size) 
			{
				_size = n;
				_str[_size] = '\0';
			}
			else 
			{
				if (n > _capacity)
					reserve(n);

				for (size_t i = _size; i < n; ++i)
					_str[i] = ch;
				_size = n;
				_str[_size] = '\0';
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				if (_capacity == 0)
				{
					reserve(2);
				}
				else
				{
					reserve(_capacity * 2);
				}
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
				reserve(_size + len);

			strcpy(_str + _size, str);
			_size += len;
		}
		string& operator+=(char ch)
		{
			this->push_back(ch);
			return *this;
		}
		string& operator+=(const char* str)
		{
			this->append(str);
			return *this;
		}

		string& insert(size_t pos, char ch)
		{
			assert(pos < _size);
			if (_size == _capacity)
			{
				reserve(_capacity * 2);
			}

			size_t end = _size;
			while (end >= pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}

			_str[pos] = ch;
			++_size;

			return *this;
		}

		string& insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			size_t end = _size;
			while (end >= pos)
			{
				_str[end + len] = _str[end];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (_size - pos <= len)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}
		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == ch)
					return i;
			}

			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			const char* p = strstr(_str + pos, str);
			if (p == nullptr)
				return npos;
			else
				return p - _str;
		}
		bool operator<(const string& s)
		{
			return strcmp(_str, s._str) < 0;
		}

		bool operator==(const string& s)
		{
			return strcmp(_str, s._str) == 0;
		}

		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s)
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s)
		{
			return !(*this < s);
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static size_t npos;
	};

	size_t string::npos = -1;

	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}

		return out;
	}

	istream& operator >> (istream& in, string& s)
	{
		while (1)
		{
			char ch = in.get();
			if (ch == ' ' || ch == '\n')
				break;
			else
				s += ch;
		}

		return in;
	}
}
void test_string1()
{
	bit::string s1("hello");
	s1.push_back('x');
	s1.push_back('y');
	s1.append("world");
	s1 += '!';
	s1 += "hello world";
	cout << s1 << endl;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		s1[i] += 1;
		cout << s1[i] << " ";
	}
	cout << endl;
	bit::string::iterator it1 = s1.begin();
	while (it1 != s1.end())
	{
		*it1 -= 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
	for (auto& ch : s1)
	{
		ch += 1;
		cout << ch << " ";
	}
	cout << endl;

	bit::string s2("hello");
	s2 += 'x';
	s2.resize(3);
	s2.resize(7, 'x');
	s2.resize(15, 'x');
}

void test_string2()
{
	bit::string s1("hello");
	s1.insert(2, 'e');
	cout << s1 << endl;

	s1.insert(2, "world");
	cout << s1 << endl;

	bit::string s2("hello world wrold");
	cout << s2 << endl;
	s2.erase(5, 6);
	cout << s2 << endl;

	//s2.erase(5);
	s2.erase(5, 10);
	cout << s2 << endl;

	bit::string s;
	cin >> s;
	cout << s << endl;
}

int main()
{
	test_string2();

	return 0;
}