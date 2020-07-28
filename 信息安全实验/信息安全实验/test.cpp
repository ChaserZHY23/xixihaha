#include<math.h>
#include<time.h>
#include<cstdlib>
#include<iostream>
#include <stdbool.h>
#include<string.h>
//#include"ProRPN.h"
using namespace std;
unsigned __int64 Esha[40];//存放A私钥加密摘要后的值
unsigned __int64 Ehm[40];//存放B公钥加密摘要后的值
unsigned __int64 Em[100];//方便起见,这里消息长度为100
unsigned __int64 eax;
int lenm = 0;
unsigned __int64 quick(unsigned __int64 a, unsigned __int64 b, unsigned __int64 c) {
	unsigned __int64 ans = 1;
	a = a%c;
	while (b != 0)

	{
		if (b & 1)
		{
			ans = (ans*a) % c;
		}
		b >>= 1;    //二进制的移位操作，相当于每次除以2，用二进制看，就是我们不断的遍历b的二进制位
		a = (a*a) % c;
	}
	return ans;
}
unsigned __int64 Rpn(unsigned __int64 n, unsigned __int64 m) {
	unsigned __int64 x;
	int flag, s = 1;
	flag = 1;
	unsigned __int64* res;//试除保留余数的结果
	res = new(unsigned __int64);
	*res = 0.0;
	srand((unsigned)time(NULL));//设置随机种子
	while (flag > 0) {
		x = rand() % (m - n) + n;
		if (x % 2 != 0) {
			flag = -1;
		}
	}//生成随机数在2的16次到2的17次方之间
	 /*cout << x << endl;
	 cout << "小素数试除过程:";*/
	while (s > 0) {
		if (trydiv(x, res) == 0) {
			x += 2;
		}
		else {
			return x;
		}
	}
}
bool trydiv(unsigned __int64 x, unsigned __int64* y) {
	cout << endl << x << endl << "小素数试除:" << endl;
	int count = 0;
	int arr[168] = { 2, 3, 5 ,7, 11 ,13 ,17 ,19, 23 ,29 ,31 ,37 ,41, 43, 47 ,53 ,59, 61, 67, 71 ,73, 79 ,83 ,89, 97 ,101 ,103, 107,
		109 ,113, 127 ,131 ,137, 139, 149, 151 ,157 ,163, 167 ,173 ,179 ,181 ,191 ,193 ,197 ,199 ,211 ,223,
		227, 229 ,233 ,239, 241, 251, 257 ,263, 269, 271, 277,281, 283 ,293 ,307, 311 ,313 ,317, 331,337,
		347 ,349, 353, 359 ,367, 373 ,379, 383, 389, 397 ,401, 409, 419, 421, 431 ,433 ,439 ,443, 449 ,457,
		461, 463 ,467, 479 ,487, 491 ,499, 503, 509, 521 ,523, 541 ,547, 557 ,563, 569 ,571, 577, 587, 593,
		599 ,601,607, 613, 617, 619 ,631, 641, 643, 647, 653 ,659, 661 ,673, 677, 683 ,691 ,701, 709, 719,
		727, 733 ,739 ,743 ,751, 757 ,761 ,769, 773 ,787, 797 ,809 ,811 ,821 ,823 ,827 ,829,839 ,853,857,
		859 ,863, 877 ,881, 883, 887, 907, 911, 919, 929, 937,941, 947 ,953,967, 971, 977 ,983, 991, 997 };//1000以内的小素数
	for (int i = 0; i < 168; i++) {
		*y = x%arr[i];
		cout << *y << "  ";
		count++;
		if (count == 21) { cout << endl; count = 0; }
		if (*y == 0) {
			return false;
		}
		if (i == 167) {
			cout << endl;
			return true;
		}
	}
}
bool Miller_Rabin(unsigned __int64 n, int z) {
	//int count = 5,i=0;
	unsigned __int64 t = 0;
	unsigned __int64 b = n - 1;
	while ((b & 1) == 0)//二进制最后一位为0
	{
		t++;
		b >>= 1;
	}
	//现在的a^(b*2^t)=1(mod n)
	unsigned __int64 x = quick(z, b, n);
	/*i++;
	count--;*/
	for (unsigned __int64 i = 1; i <= t; i++)
	{
		unsigned __int64 y = quick(x, 2, n);
		if (y == 1 && x != 1 && x != n - 1) return false;   //这里的意思是如果a^(d*2^r)是1，但是a^(d*2^(r-1))不是1也不是n-1的情况，这时候我们认为是合数 ,x^2=1modn,要能够整除x^2-1也就是(x+1)*(x-1),当x=x+1,只有x=n-1才能被n整除,x=x-1,只有x=1才能被n整除 
		x = y;
	}
	if (x != 1)
		return false;
	else
		return true;


}
bool proRPN(unsigned __int64 x, unsigned __int64 y) {
	unsigned __int64* res;//试除保留余数的结果
	int flag = 0, flag1 = 1;
	int count = 0;
	unsigned __int64 result = 0.0;
	int a[5] = { 3,5,7,11,13 };
	res = new(unsigned __int64);
	*res = 0.0;
	result = Rpn(x, y);
	cout << "米勒-罗宾素性检测:" << endl;
	while (flag == 0) {
		for (count = 0; count < 5; count++) {
			if (Miller_Rabin(result, a[count]) == 0) {
				cout << "检测失败重新生成" << endl;
				result += 2;
				count = 0;
				while (flag1 == 1) {
					if (trydiv(result, res) == 0) {
						result += 2;
					}
					else {
						break;
					}
				}
			}
			else {
				cout << "第" << count + 1 << "次米勒检验成功" << endl;
			}
		}
		if (count == 5) {
			cout << "检测通过,素数为:" << result << endl;
			eax = result;
			flag = -1;
			return true;
		}
	}
}
void productrpn(unsigned __int64*pa, unsigned __int64*qa, unsigned __int64*pb, unsigned __int64*qb) {
	if (proRPN(pow(2, 11), pow(2, 13)) == 1) {
		*pa = eax;

	}
	if (proRPN(pow(2, 17), pow(2, 18)) == 1) {
		*qa = eax;
	}
	if (proRPN(pow(2, 13), pow(2, 14)) == 1) {
		*pb = eax;
	}
	if (proRPN(pow(2, 18), pow(2, 19)) == 1) {
		*qb = eax;
	}
}
unsigned __int64 rsa(unsigned __int64 p, unsigned __int64 q, unsigned __int64 e) {
	unsigned __int64 g, k, r, n1, n2;
	__int64 b1 = 0, b2 = 1, t;
	g = (p - 1)*(q - 1);
	n1 = g;
	n2 = e;
	while (1)
	{
		k = n1 / n2;//k为除数
		r = n1 - k*n2;//r为n1/n2的余数
		if (r != 0)
		{
			n1 = n2;
			n2 = r;
			t = b2;
			b2 = b1 - k*b2;//最终得到的b2就是欧几里得扩展算法倒回去求得的数,无论b2是正还是负,最后都(b2+g)%g,得到一个正数
			b1 = t;
		}
		else
		{
			break;
		}
	}
	return (g + b2) % g;
}

void ERSA(unsigned __int64 da, unsigned __int64 eb, char* s1, unsigned __int64* sha1, unsigned __int64 pqA, unsigned __int64 pqB) {
	int lens, i;
	lens = 40;//一开始就写好的40个值组成的一组摘要值
	for (i = 0;; i++) {
		if (s1[i] == -52) {
			break;
		}
		lenm++;
	}
	//lenm = strlen(s1);//消息长度
	cout << endl << "发送方私钥加密摘要值后为:";
	for (i = 0; i < lens; i++) {
		Esha[i] = quick(sha1[i], da, pqA);
		cout << hex << Esha[i];
		//Esha[i] = quick(9, 29, 299);
	}//用A的私钥加密摘要值
	cout << endl << endl << "发送方用接收方公钥加密消息后的值为:";
	for (i = 0; i < lenm; i++) {
		Em[i] = quick((unsigned __int64)s1[i], eb, pqB);
		cout << hex << Em[i];
	}//用B的公钥加密消息
	cout << endl << endl << "发送方用接收方的公钥加密已经经过发送方私钥处理过的摘要值后为:";
	for (i = 0; i < 40; i++) {
		Ehm[i] = quick(Esha[i], eb, pqB);
		cout << hex << Ehm[i];
	}//用B的公钥加密A私钥加密过后的摘要值
}
void DRSA(unsigned __int64 ea, unsigned __int64 db, unsigned __int64 pqA, unsigned __int64 pqB) {
	unsigned __int64 Dsha[40];
	unsigned __int64 Dhm[40];
	unsigned __int64 dm[100];
	//__int64 Dm[100];
	cout << endl << endl << "解密用接收方公钥加密的经过发送方私钥处理过的摘要值:";
	for (int i = 0; i < 40; i++) {
		Dhm[i] = quick(Ehm[i], db, pqB);
		cout << hex << Dhm[i];
	}
	cout << endl << endl << "解密发送方发来的摘要值:";
	for (int i = 0; i < 40; i++) {
		Dsha[i] = quick(Esha[i], ea, pqA);
		cout << hex << Dsha[i];
		//		Dsha[i] = quick(211, 173,299);
	}
	cout << endl << endl << "解密发送方发来的密文:";
	for (int i = 0; i < lenm; i++) {
		dm[i] = quick(Em[i], db, pqB);
		cout << (char)dm[i];
	}
	cout << endl << "接收方B的私钥能解密用接收方B公钥加密的信息,表明该消息是发送方A发送给B的,只有B才能解开信息" << endl;
	cout << "用发送方A的公钥验证经过A私钥签名的摘要值,得到的摘要值与正确的摘要值一样,表明,消息内容没有被修改" << endl;
}


