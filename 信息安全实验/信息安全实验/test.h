#pragma once
#include<iostream>
using namespace std;
unsigned __int64 quick(unsigned  __int64 a, unsigned  __int64 b, unsigned __int64 c);//快速模平方算法
unsigned __int64  Rpn(unsigned  __int64 n, unsigned  __int64 m);//Random prime number 随机素数
bool Miller_Rabin(unsigned __int64  n, int z);//素性检测
bool proRPN(unsigned __int64 x, unsigned __int64  y);
void productrpn(unsigned __int64 *pa, unsigned __int64 *qa, unsigned __int64 *pb, unsigned __int64 *qb);
bool trydiv(unsigned __int64 x, unsigned __int64* y);
unsigned __int64 rsa(unsigned __int64 p, unsigned __int64 q, unsigned __int64 e);//辗转相除求私钥d
void ERSA(unsigned __int64 da, unsigned __int64 eb, char* s1, unsigned __int64* sha1, unsigned __int64 pqA, unsigned __int64 pqB);//加密函数
void DRSA(unsigned __int64 ea, unsigned __int64 db, unsigned __int64 pqA, unsigned __int64 pqB);//解密函数
class RSA {
private:
	unsigned __int64 p, q;//p,q为两个大素数
	unsigned __int64 pq;//两个大素数的乘积
	unsigned __int64 e;//公钥
	unsigned __int64 d;//私钥
	char s[100];//消息
	unsigned __int64 sha[40];//消息的摘要值,这里为随意写的160bit值
public:
	RSA() {//将题目中要求的数据放入构造函数
		e = 17;
		s[0] = '3'; s[1] = '2'; s[2] = '6'; s[3] = '5'; s[4] = '5';
		unsigned __int64 x[40] = { 0xa,0x9,0x9,0x9,0x3,0xe,0x3,0x6,0x1,0x7,0x0,0x6,0x8,0x1,0x6,0xa,0xb,0xa,0x3,0xe,
			0x2,0x5,0x7,0x1,0x7,0x8,0x5,0x0,0xc,0x2,0x6,0xc,0x9,0xc,0xd,0x0,0xd,0x8,0x9,0xd };
		for (int i = 0; i < 40; i++) {
			sha[i] = x[i];
		}
	}
	void putp(const unsigned __int64 *x) {
		p = *x;
	}
	unsigned __int64 getp() {
		return p;

	}
	void putq(const unsigned __int64 *x) {
		q = *x;
	}
	unsigned __int64 getq() {
		return q;

	}
	void pute(const unsigned __int64 x) {
		e = x;
	}
	unsigned __int64 gete() {
		return e;
	}
	void putd(const unsigned __int64 x) {
		d = x;
	}
	unsigned __int64 getd() {
		return d;
	}
	void puts() {
		int len;
		cout << "请输入要明文的长度:";
		cin >> len;
		for (int i = 0; i < len; i++) {
			cin >> s[i];
		}
	}
	char* gets() {
		return s;
	}
	void putpq() {
		pq = p*q;
	}
	unsigned __int64 getpq() {
		return pq;
	}
	unsigned __int64* getsha() {
		return sha;
	}
	void prits() {
		cout << "发送方明文:";
		int i = 0;
		while (s[i] != -52) {
			cout << s[i];
			i++;
		}
		cout << endl << endl;
	}
	void pritsha() {
		cout << "发送方消息摘要:";
		int i = 0;
		while (i <40) {
			cout << hex << sha[i];
			i++;
		}
		cout << endl;
	}
};

