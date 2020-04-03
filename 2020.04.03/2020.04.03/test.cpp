#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <assert.h>
using namespace std;

void swap_int(int* pa, int* pb);
void swap_double(double* pa, double* pb);

// 泛型编程 -> 可以解决需要写多个swap函数的问题，着多个swap函数逻辑是相同，代码中处理类型不一样
// 模拟库中swap实现
namespace bit
{
	// 函数模板
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
	// C语言中，我们得写两个函数，如果更多类型的对象需要交换，那么这里还需要写更多swap函数
	int a = 0, b = 1;
	double c = 1.1, d = 2.2;
	// swap_int(&a, &b);
	// swap_double(&c, &d);

	// C++如何解决，C++标准库中就有一个swap函数可以使用
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
	// 编译器自己去推演，隐式示例化
	Add(a1, a2);
	Add(d1, d2);
	Add(a1, (int)d2);

	// 指定T的类型，显式的实例化
	Add<int>(a1, d2);
	Add<double>(a1, d2);

	// 想调用Func函数，只能显示实例化
	Func<int>(10);

	return 0;
}

 专门处理int的加法函数
 现成的  优先用它
int Add(int left, int right)
{
	return left + right;
}

// 通用加法函数
// 模板，需要实例化才能调用
template<class T>
T Add(T left, T right)
{
	return left + right;
}

int main()
{
	Add(1, 2);      // ->现成函数
	Add(1.1, 2.2);  // ->模板实例化的
	Add<int>(1, 2);

	return 0;
}

namespace bit_c
{
	// 顺序表 -- 可以动态增长的数组
	// C语言定义的顺序表
	// 数据和方法是分开定义
	// 问题1：数据是可以被随便改的  CPP如何解决->类的封装 先把数据和方法放到一起，通过访问限定符保护一起
	// 问题2：代码冗余，要同时满足SeqList seq1,要存int; SeqList seq2,存double.
	//        面对问题2，C就能去定义出两份实现，代码逻辑一样，类型不一样  CPP如何解决-》类模板
	typedef int SLDataType;
	typedef struct SeqList
	{
		SLDataType*   _a;
		size_t _size;
		size_t _capacity;
	}SeqList;

	void SeqListInit(SeqList* ps, size_t n)     // cpp->构造函数
	{}
	void SeqListDestory(SeqList* ps)            // cpp->析构函数
	{}
	void SeqListPrint(SeqList* ps);
	void SeqListCheckCapacity(SeqList* ps);
	void SeqListPushBack(SeqList* ps, SLDataType x)  // c两个参数，cpp->看起来只有一个参数，实际也是两个，有一个是隐含的this
	{}
	void SeqListPopBack(SeqList* ps);
}

namespace bit_cpp
{
	// typedef int SLDataType;
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

		// a[i]
		// a[i] = 0;
		T& operator[](size_t i)
		{
			// 断言i访问的位置是否合法
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
	// C中使用顺序表
	bit_c::SeqList seqc;
	bit_c::SeqListInit(&seqc, 10);
	// ...
	bit_c::SeqListPushBack(&seqc, 1);
	bit_c::SeqListPushBack(&seqc, 2);
	bit_c::SeqListPushBack(&seqc, 3);
	bit_c::SeqListDestory(&seqc);


	// CPP中使用顺序表
	bit_cpp::SeqList<int> seqcpp1;
	seqcpp1.PushBack(1);
	seqcpp1.PushBack(2);
	seqcpp1.PushBack(3);

	// 读第i个位置的数据
	cout << seqcpp1[0] << endl;
	// 写第i个位置数据
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

	// 以下两种方式都不常用
	std::string s4(s3, 5, 5);
	std::string s5(5, 'a');

	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;
	std::cout << s4 << std::endl;
	std::cout << s5 << std::endl;

	// 像遍历数组一样，获取数组中的每个字符
	for (size_t i = 0; i < s1.size(); ++i)
	{
		std::cout << s1[i] << " ";
	}
	std::cout << std::endl;


	return 0;
}
